#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL)
{
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
}

MyGLWidget::~MyGLWidget ()
{
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();  

  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  glEnable(GL_DEPTH_TEST);
  carregaShaders();
  iniEscena ();
  iniCamera ();
}

void MyGLWidget::iniEscena ()   // Cal modificar aquest mètode...
{ camera = false;
  creaBuffersTerra();
  //creaBuffersArbre();
  creaBuffersPilota();
  creaBuffersPatricio();
  Pmin = glm::vec3(0.0,0.0,0.0);
  Pmax = glm::vec3(20.0,6.0,20.0); 
  centreEsc = glm::vec3 (5, 0, 5);
  radiEsc = 10;
  centreBaseArbre = glm::vec3(-0.5, -0.35, 0.0);
  posPilota = glm::vec3(10, 0, 10);
}

void MyGLWidget::iniCamera ()   // Cal modificar aquest mètode...
{
  angleY=- (float)M_PI/(float)6.0;
  angleX = 0.0;
  obs = centreEsc + glm::vec3(0, 2, 2*radiEsc);
  //vrp = centreEsc;
  up = glm::vec3(0,1,0);
  //ra = 1.0;
  //fov = float(M_PI/3.0);
  
  calcularParametresPerspective();
  projectTransform ();

  viewTransform ();
}
void MyGLWidget::calcularParametresPerspective()
{
if(!camera){
  fov =(float)(2 * asin((float)radiEsc/(float)(2*radiEsc)));
  zn = radiEsc;
  //zn = 1;
  zf = 4*radiEsc;
//  ra = 1;
}
else 
{
  fov =(float) (M_PI / 3.0);
  zn = 1;
  zf = 26;
 ra = 1; 
}

}
void MyGLWidget::calcularParametresEuler()
{
vrp = centreEsc;	
//vrp = (Pmin + Pmax)/2.0f;
}

void MyGLWidget::paintGL ()   // Cal modificar aquest mètode...
{
// Aquest codi és necessari únicament per a MACs amb pantalla retina.
#ifdef __APPLE__
  GLint vp[4];
  glGetIntegerv (GL_VIEWPORT, vp);
  ample = vp[2];
  alt = vp[3];
#endif

// En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
// useu els paràmetres que considereu (els que hi ha són els de per defecte)
//  glViewport (0, 0, ample, alt);
  
  // Esborrem el frame-buffer i el depth-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Activem el VAO per a pintar el terra 
  glBindVertexArray (VAO_Terra);
  modelTransformTerra ();
  glDrawArrays(GL_TRIANGLES, 0, 6);

  // Activem el VAO per a pintar la Pilota
  glBindVertexArray (VAO_Pil);
  modelTransformPilota ();
  glDrawArrays(GL_TRIANGLES, 0, pil.faces().size()*3);
  
  // Activem el VAO per a pintar el patricio
  glBindVertexArray(VAO_Patricio);
  modelTransformPatricio ();
  glDrawArrays(GL_TRIANGLES, 0, Pat.faces().size()*3);

  glBindVertexArray(0);
}

void MyGLWidget::resizeGL (int w, int h)   // Cal modificar aquest mètode...
{
  ample = w;
  alt = h;
  ra = (float)w/(float)h;
  if(ra < 1){
	  fov = (float)(2 * atan(tan(radiEsc/(2*radiEsc)/ra)));
  	  projectTransform();
  }
   else if(ra > 1 )
   {
	   projectTransform();
   } 
}

void MyGLWidget::modelTransformPilota ()
{
  glm::mat4 TG(1.f);  // Matriu de transformació
  TG = glm::translate(TG, posPilota);
  TG = glm::scale(TG, glm::vec3 (escalaPil, escalaPil, escalaPil));
  TG = glm::translate(TG, -centreBasePil);
  
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformTerra ()
{
  glm::mat4 TG(1.f);  // Matriu de transformació
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformArbre () 
{
  glm::mat4 TG (1.0f); // Matriu de transformació
  TG = glm::translate(TG, glm::vec3(2.0, 0.0, 2.0));
  TG = glm::scale(TG, glm::vec3(escalaArbre, escalaArbre, escalaArbre));
  TG = glm::translate(TG, -centreBaseArbre);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformPatricio () 
{
  // Cal completar aquest mètode
  glm::mat4 TG (1.0f); // Matriu de transformaciO
  TG = glm::translate(TG, glm::vec3(2.0, 0.0, 2.0));
  TG = glm::rotate(TG,(float)M_PI/2,glm::vec3(0.0,1.0,0.0));
  TG = glm::scale(TG, glm::vec3(escalaPat, escalaPat, escalaPat));
  TG = glm::translate(TG, -centreBasePat);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::projectTransform ()     // Cal modificar aquest mètode...
{
  glm::mat4 Proj(1.0f);  // Matriu de projecció
  Proj = glm::perspective(fov, ra, zn, zf);

  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform ()      // Cal modificar aquest mètode...
{
  glm::mat4 View(1.0f);  // Matriu de posició i orientació
if(!camera)
{	
  calcularParametresEuler();
  // View = glm::translate(View,glm::vec3(0.0,0.0,-(float)sqrt(2.0*2.0+20.0*20.0)));
   View = glm::translate(View,glm::vec3(0.0,0.0,-2*radiEsc));
  //View = glm::lookAt(obs, vrp, up);
  View = glm::rotate(View,angleX,glm::vec3(1.0,0.0,0.0));
  View = glm::rotate(View,angleY,glm::vec3(0.0,1.0,0.0));
  View = glm::translate(View,-vrp);
}
else
{
calcularParametreslookAt();
View = glm::lookAt(obs,vrp,up);

}
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
}
void MyGLWidget::calcularParametreslookAt()
{
	vrp = posPilota;
	obs = glm::vec3(centreBasePat[0],6.5,centreBasePat[2]);
	up = glm::vec3(0.0,1.0,0.0);
}
void MyGLWidget::keyPressEvent(QKeyEvent* event)  // Cal modificar aquest mètode...
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_Left: { 
	posPilota[0] -= 0.5;
	viewTransform();
      break;
    }
    case Qt::Key_Right: { 
	posPilota[0] += 0.5;
	viewTransform();
      break;
    }
    case Qt::Key_Up: { 
	posPilota[2] -= 0.5;
	viewTransform();

      break;
    }
    case Qt::Key_Down: { 
	posPilota[2] += 0.5;
	viewTransform();
      break;
    }
    case Qt::Key_C: { 
	 camera = !camera;
	 viewTransform();
         projectTransform();	 
	// Canvi de càmera...
      break;
    }
    default: event->ignore(); break;
  }

  update();
}

void MyGLWidget::mousePressEvent (QMouseEvent *e)
{
xClick = e->x();
 yClick = e->y();

  if (e->button() & Qt::LeftButton &&
      ! (e->modifiers() & (Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
  {
    DoingInteractive = ROTATE;
  }
}

void MyGLWidget::mouseReleaseEvent( QMouseEvent *)
{
  DoingInteractive = NONE;
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)  // Cal modificar aquest mètode...
{
  makeCurrent();
  if (DoingInteractive == ROTATE)
  {
    // Aquí cal completar per fer la rotació...
    angleX += (float) e->y() - (float)yClick;
    angleY += (float) e->x() - (float)xClick;
    angleX = (float)angleX / (float)100;
    angleY = (float) angleY/(float)100;
    viewTransform ();
  }

//xClick = e->x();
// yClick = e->y();

  update ();
}

void MyGLWidget::calculaCapsaModel (Model &p, float &escala, glm::vec3 &centreBase)
{
  // Càlcul capsa contenidora i valors transformacions inicials
  float minx, miny, minz, maxx, maxy, maxz;
  minx = maxx = p.vertices()[0];
  miny = maxy = p.vertices()[1];
  minz = maxz = p.vertices()[2];
  for (unsigned int i = 3; i < p.vertices().size(); i+=3)
  {
    if (p.vertices()[i+0] < minx)
      minx = p.vertices()[i+0];
    if (p.vertices()[i+0] > maxx)
      maxx = p.vertices()[i+0];
    if (p.vertices()[i+1] < miny)
      miny = p.vertices()[i+1];
    if (p.vertices()[i+1] > maxy)
      maxy = p.vertices()[i+1];
    if (p.vertices()[i+2] < minz)
      minz = p.vertices()[i+2];
    if (p.vertices()[i+2] > maxz)
      maxz = p.vertices()[i+2];
  }
  escala = 1.0/(maxy-miny);
  centreBase[0] = (minx+maxx)/2.0; centreBase[1] = miny; centreBase[2] = (minz+maxz)/2.0;
}

void MyGLWidget::calculaCapsaPatricio (Model &p, float &escala, glm::vec3 &centreBasePat)
{
  // Càlcul capsa contenidora i valors transformacions inicials
  float minx, miny, minz, maxx, maxy, maxz;
  minx = maxx = p.vertices()[0];
  miny = maxy = p.vertices()[1];
  minz = maxz = p.vertices()[2];
  for (unsigned int i = 3; i < p.vertices().size(); i+=3)
  {
    if (p.vertices()[i+0] < minx)
      minx = p.vertices()[i+0];
    if (p.vertices()[i+0] > maxx)
      maxx = p.vertices()[i+0];
    if (p.vertices()[i+1] < miny)
      miny = p.vertices()[i+1];
    if (p.vertices()[i+1] > maxy)
      maxy = p.vertices()[i+1];
    if (p.vertices()[i+2] < minz)
      minz = p.vertices()[i+2];
    if (p.vertices()[i+2] > maxz)
      maxz = p.vertices()[i+2];
  }
  escala = 6.0/(maxy-miny);
  centreBasePat[0] = (minx+maxx)/2.0; centreBasePat[1] = miny; centreBasePat[2] = (minz+maxz)/2.0;
}
void MyGLWidget::creaBuffersPilota ()
{
  // Carreguem el model de l'OBJ - Atenció! Abans de crear els buffers!
  pil.load("./models/Pilota.obj");

  // Calculem la capsa contenidora del model
  calculaCapsaModel (pil, escalaPil, centreBasePil);
  
  // Creació del Vertex Array Object del Patricio
  glGenVertexArrays(1, &VAO_Pil);
  glBindVertexArray(VAO_Pil);

  // Creació dels buffers del model patr
  GLuint VBO_Pil[2];
  // Buffer de posicions
  glGenBuffers(2, VBO_Pil);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Pil[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*pil.faces().size()*3*3, pil.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  // Buffer de component difusa usada com a color
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Pil[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*pil.faces().size()*3*3, pil.VBO_matdiff(), GL_STATIC_DRAW);

  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  glBindVertexArray(0);
}

void MyGLWidget::creaBuffersArbre () 
{
  // Dades de les coordenades dels vèrtexs
  glm::vec3 Vertices[12];  
  Vertices[0] = glm::vec3(-0.55, -0.35, 0.0);  // tronc de l'arbre
  Vertices[1] = glm::vec3(-0.45, -0.35, 0.0);
  Vertices[2] = glm::vec3(-0.55, 0.05, 0.0);
  Vertices[3] = glm::vec3(-0.55, 0.05, 0.0);
  Vertices[4] = glm::vec3(-0.45, -0.35, 0.0);
  Vertices[5] = glm::vec3(-0.45, 0.05, 0.0);
  Vertices[6] = glm::vec3(-0.65, 0.05, 0.01);  // fulles de l'arbre
  Vertices[7] = glm::vec3(-0.35, 0.05, 0.01);
  Vertices[8] = glm::vec3(-0.5, 0.35, 0.01);
  Vertices[9] = glm::vec3(-0.35, 0.25, 0.01);
  Vertices[10] = glm::vec3(-0.65, 0.25, 0.01);
  Vertices[11] = glm::vec3(-0.5, -0.05, 0.01);
  
  // Dades de les colors dels vèrtexs
  glm::vec3 Colors[12];
  Colors[0] = glm::vec3(1.0, 0.6, 0.3);  // marró
  Colors[1] = glm::vec3(1.0, 0.6, 0.3);
  Colors[2] = glm::vec3(1.0, 0.6, 0.3);
  Colors[3] = glm::vec3(1.0, 0.6, 0.3);
  Colors[4] = glm::vec3(1.0, 0.6, 0.3);
  Colors[5] = glm::vec3(1.0, 0.6, 0.3);
  Colors[6] = glm::vec3(0.0, 1.0, 0.0);  // verd
  Colors[7] = glm::vec3(0.0, 1.0, 0.0);
  Colors[8] = glm::vec3(0.0, 1.0, 0.0);
  Colors[9] = glm::vec3(0.0, 1.0, 0.0);
  Colors[10] = glm::vec3(0.0, 1.0, 0.0);
  Colors[11] = glm::vec3(0.0, 1.0, 0.0);

  escalaArbre = 10.0/0.7;  // volem l'arbre d'alçada 10
  
  // Creació del Vertex Array Object (VAO) que usarem per pintar
  glGenVertexArrays(1, &VAO_Arbre);
  glBindVertexArray(VAO_Arbre);

  GLuint VBOs[2];
  glGenBuffers(2, VBOs);
  // Creació del buffer amb les coordenades dels vèrtexs
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  // Creació del buffer amb els colors dels vèrtexs
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::creaBuffersTerra ()
{
  // Dades del terra
  // VBO amb la posició dels vèrtexs
  glm::vec3 posterra[6] = {
	glm::vec3(0.0, 0.0, 20.0),
	glm::vec3(20.0, 0.0, 20.0),
	glm::vec3(0.0, 0.0, 0.0),
	glm::vec3(0.0, 0.0, 0.0),
	glm::vec3(20.0, 0.0, 20.0),
	glm::vec3(20.0, 0.0, 0.0),
  }; 

  glm::vec3 color(0.0,0.6,0.0);

  // Fem que aquest material afecti a tots els vèrtexs per igual
  glm::vec3 colterra[6] = {
	color, color, color, color, color, color
  };

// Creació del Vertex Array Object del terra
  glGenVertexArrays(1, &VAO_Terra);
  glBindVertexArray(VAO_Terra);

  GLuint VBO_Terra[2];
  glGenBuffers(2, VBO_Terra);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(posterra), posterra, GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colterra), colterra, GL_STATIC_DRAW);

  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  glBindVertexArray(0);
}

void MyGLWidget::creaBuffersPatricio ()
{
	
GLuint VBO_Patricio[2];
Pat.load("./models/Patricio.obj");
calculaCapsaPatricio(Pat,escalaPat,centreBasePat);
glBindVertexArray(0);
glGenVertexArrays(1,&VAO_Patricio);
glBindVertexArray(VAO_Patricio);
glGenBuffers(2,VBO_Patricio);
glBindBuffer(GL_ARRAY_BUFFER,VBO_Patricio[0]);
glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*Pat.faces().size()*3*3,Pat.VBO_vertices(),GL_STATIC_DRAW);
glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
glEnableVertexAttribArray(vertexLoc);
  // Cal completar aquest mètode afegint també en el .h els atributs que 
glBindBuffer(GL_ARRAY_BUFFER,VBO_Patricio[1]);
glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*Pat.faces().size()*3*3,Pat.VBO_matdiff(),GL_STATIC_DRAW);
glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
glEnableVertexAttribArray(colorLoc);
glBindVertexArray(0);
  // siguin necessaris...
}
 
void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("./shaders/basicShader.frag");
  vs.compileSourceFile("./shaders/basicShader.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");

  // Demanem identificadors per als uniforms del vertex shader
  transLoc = glGetUniformLocation (program->programId(), "TG");
  projLoc = glGetUniformLocation (program->programId(), "proj");
  viewLoc = glGetUniformLocation (program->programId(), "view");
}


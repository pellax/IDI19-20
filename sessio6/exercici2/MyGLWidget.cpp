#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL)
{
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
  scale = 1.0f;
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
  glEnable(GL_DEPTH_TEST);
  /*ra = 1.0f;
  fov = (float)M_PI/2.0f;
  Zf = 3.0f;
  Zn = 0.4f; 
  obs = glm::vec3(0,0,1);
  vrp = glm::vec3(0,0,0);
  up = glm::vec3(0,1,0);
  */
 
  angleX = 0.0;
  angleY = 0.0;
  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  Pmin = glm::vec3(-2.5,-0.0,-2.5); 
  Pmax = glm::vec3(2.5,4.0,2.5);
  calculRadi();
  d = 2 * R;
  orto = true;
  projectTransform();
  viewTransform();
  
  creaBuffers();
  creaBuffersTerra();

}
void MyGLWidget::paintGL () 
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
  
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  /// Carreguem la transformació de model
  modelTransform ();

  // Activem el VAO per a pintar la caseta 
  glBindVertexArray (VAO_Casa);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, m.faces().size()*3);
  modelTransformTerra();
  glBindVertexArray(VAO_Terra);
  glDrawArrays(GL_TRIANGLES,0,6);
  glBindVertexArray (0);
}

void MyGLWidget::modelTransform () 
{
  // Matriu de transformació de model
  CalculCaixaPatricio();
  calculCentreTapaPatricio();
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::translate(transform,-CentreBasePat);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);

}
void MyGLWidget::modelTransformTerra()
{
	glm::mat4 transform(1.0f);
	transform = glm::scale(transform,glm::vec3((float)5.0/(float)(1.0 - -1.0),1,(float)5.0/(float)(1.0 - -1.0)));
	transform = glm::translate(transform,glm::vec3(0,1,0));
	glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}
void MyGLWidget::CalculCaixaPatricio()

{
	xmin = m.vertices()[0];
	xmax = m.vertices()[0];
	ymin = m.vertices()[1];
	ymax = m.vertices()[1];
	zmin = m.vertices()[2];
	zmax = m.vertices()[2];
	for(unsigned int i = 0;i < m.vertices().size();i += 3)
{
		if(m.vertices()[i] > xmax)xmax = m.vertices()[i];

		if(m.vertices()[i] < xmin)xmin = m.vertices()[i];
		if(m.vertices()[i + 1] > ymax)ymax = m.vertices()[i + 1];
		if(m.vertices()[i + 1] < ymin)ymin = m.vertices()[i + 1];
		if(m.vertices()[i + 2] > zmax)zmax = m.vertices()[i + 2];
		if(m.vertices()[i + 2] < zmin)zmin = m.vertices()[i + 2];
}
}

void MyGLWidget::calculCentreTapaPatricio()
{
CentreBasePat=glm::vec3((float)(xmin + xmax)/(float)2,ymin,(float)(zmin + zmax)/(float)2);

}
void MyGLWidget::mousePressEvent(QMouseEvent *event){
	xant = event ->x() ;
	yant = event->y();
}
void MyGLWidget::calculScalePat()
{
	scale =(float) 4 /(float)(ymax-ymin);
}
void MyGLWidget::resizeGL (int w, int h) 

{
 
  ample = w;
  alt = h;
  ra = (float)w/(float)h;
  if(!orto)

	 {
	  if(ra < 1) 
	  {
	  //calculRadi();
	 // fov =(float)(2 * asin(R/d));
		 fov = (float)(2 * atan(tan(R/d)/ra));
			  projectTransform();
	  }
	  else if(ra > 1)
	  {
         	 projectTransform();
	  }
	 }else
	 {
		if(ra < 1){
		     b = (-R * ra)/2;
		     t = (R * ra)/2;
		     projectTransform();
		}
	        else if(ra > 1){
	             l = (-R * ra)/2;
	     	     r =  (R * ra)/2;	     
		     projectTransform();
		}	
	 }
	  }


void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }
    case Qt::Key_O:{
      orto = !orto ;
      projectTransform();
      
      break;
		   }
    default: event->ignore(); 
	     break;
  }
  update();
}
void MyGLWidget::mouseMoveEvent(QMouseEvent *e){
makeCurrent();
angleY +=(float) e->x()- (float)xant;
angleX +=(float) e->y()-(float)yant;
angleY = (float)angleY / (float)100;
angleX = (float)angleX/(float)100;	
//xant = e->x();
//yant = e->y();
viewTransform();

update();
}

void MyGLWidget::creaBuffers () 
{
  // Dades de la caseta
  // Dos VBOs, un amb posició i l'altre amb color
  // 
  // 
  
	/*glm::vec3 posicio[9] = {
	  

	glm::vec3(-0.5, -1.0, -0.5),
	glm::vec3( 0.5, -1.0, -0.5),
	glm::vec3(-0.5,  0.0, -0.5),
	glm::vec3(-0.5,  0.0, -0.5),
	glm::vec3( 0.5, -1.0, -0.5),
	glm::vec3( 0.5,  0.0, -0.5),
	glm::vec3( 0.5,  0.0, -0.5),
	glm::vec3( 0.0,  0.6, -0.5),
	glm::vec3(-0.5,  0.0, -0.5)
  }; 
  glm::vec3 color[9] = {
	glm::vec3(1,0,0),
	glm::vec3(0,1,0),
	glm::vec3(0,0,1),
	glm::vec3(0,0,1),
	glm::vec3(0,1,0),
	glm::vec3(1,0,0),
	glm::vec3(1,0,0),
	glm::vec3(0,1,0),
	glm::vec3(0,0,1)
  };

  */
  // Creació del Vertex Array Object per pintar
  
  m.load("./models/Patricio.obj");
  glBindVertexArray (0);

  glGenVertexArrays(1, &VAO_Casa);
  glBindVertexArray(VAO_Casa);

  
  glGenBuffers(1, &VBO_vertices);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_vertices);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc

  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);
  glGenBuffers(1,&VBO_matdiff);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_matdiff);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/basicShader.frag");
  vs.compileSourceFile("shaders/basicShader.vert");
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
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  projLoc = glGetUniformLocation(program->programId(),"proj");
  viewLoc = glGetUniformLocation(program->programId(),"view");
}
void MyGLWidget::projectTransform()
{       glm:: mat4 Proj;
	calcularParametresPerspective();						
	calcularParametresOrtho();
	if(!orto)
	{
	 Proj = glm::perspective(fov,ra,Zn,Zf);
	}
	else
	{
	 Proj = glm::ortho(l,r,b,t,Zn,Zf);
	}
	glUniformMatrix4fv(projLoc,1,GL_FALSE,&Proj[0][0]);
}
void MyGLWidget::calcularParametresOrtho()
{
l = -R;
r = R;
t = R;
b = -R;
}
void MyGLWidget::viewTransform()
{
//	calcularParametreslookAt();
//	glm::mat4 View = glm::lookAt(obs,vrp,up);
        calcularParametresEuler();
	glm::mat4 View(1.0f);
	View = glm::translate(View,glm::vec3(0.0,0.0,-d));
	View = glm::rotate(View,angleX,glm::vec3(1.0,0.0,0.0));
        View = glm::rotate(View,angleY,glm::vec3(0.0,1.0,0.0));
        View = glm::translate(View,-vrp);
	
	glUniformMatrix4fv(viewLoc,1,GL_FALSE,&View[0][0]);

}
void MyGLWidget::calculRadi()
{
	
  R = glm::distance(Pmin,Pmax)/2;

}
void MyGLWidget:: calcularParametreslookAt()
{
	vrp = (Pmin + Pmax)/2.0f;
	obs = vrp +(d*glm::vec3(0,0,1));
	up = glm::vec3 (0,1,0);
}
void MyGLWidget::calcularParametresPerspective()
{
	fov =(float)(2 * asin(R/d));
	Zn =  R ;
	Zf = 3 * R;
//	ra = 1.0f ;
}
void MyGLWidget::calcularParametresEuler(){
vrp = (Pmin + Pmax)/2.0f;

}	
void MyGLWidget::creaBuffersTerra()
{

//  glBindVertexArray (0);

  glGenVertexArrays(1, &VAO_Terra);
  glBindVertexArray(VAO_Terra);
  glm::vec3 Vertices[6];
  Vertices[0] = glm::vec3 (-1.0,-1.0,1.0);
  Vertices[1] = glm::vec3 (-1.0,-1.0,-1.0);
  Vertices[2] = glm::vec3 (1.0,-1.0,1.0);
  Vertices[3] = glm::vec3 (1.0,-1.0,1.0);
  Vertices[4] = glm::vec3 (-1.0,-1.0,-1.0);
  Vertices[5] = glm::vec3 (1.0,-1.0,-1.0);

  glGenBuffers(1, &VBO_verticesterra);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_verticesterra);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(vertexLoc,3,GL_FLOAT,GL_FALSE,0,0);
  glEnableVertexAttribArray(vertexLoc);	
  glm::vec3 Colors[6];
  Colors[0] = glm::vec3(1.0,0.0,1.0);
  Colors[1] = glm::vec3(1.0,0.0,1.0);
  Colors[2] = glm::vec3(1.0,0.0,1.0);
  Colors[3] = glm::vec3(1.0,0.0,1.0);
  Colors[4] = glm::vec3(1.0,0.0,1.0);
  Colors[5] = glm::vec3(1.0,0.0,1.0);
  glGenBuffers(1, &VBO_colorsterra);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_colorsterra);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
  glVertexAttribPointer(colorLoc,3,GL_FLOAT,GL_FALSE,0,0);
  glEnableVertexAttribArray(colorLoc);
  glBindVertexArray(0);
}

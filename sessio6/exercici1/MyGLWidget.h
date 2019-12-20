#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include"./Model/Model.h"
class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core 
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);

  private:
    void calculScalePat();
    void creaBuffers ();
    void creaBuffersTerra();
    void carregaShaders ();
    void modelTransform ();
    void modelTransformTerra();
    void projectTransform();
    void viewTransform();
    void calculCentreTapaPatricio();
    void CalculCaixaPatricio();
    void calcularParametresPerspective();
    void calcularParametreslookAt();
    void calcularParametresOrtho();
    void calculRadi();
    void calcularParametresEuler();
    Model m;
    // attribute locations
    GLuint vertexLoc, colorLoc,projLoc,viewLoc;
    // uniform locations
    GLuint transLoc;
    // VAO i VBO names
    GLuint VAO_Casa,VBO_vertices,VBO_matdiff,VAO_Terra,VBO_verticesterra,VBO_colorsterra;
    // Program
    QOpenGLShaderProgram *program;
    // Viewport
    GLint ample, alt;
    // Internal vars
    float scale,fov,Zn,Zf,R,ra,d,xmax,xmin,ymax,ymin,zmax,zmin,l,r,b,t,angleY,angleX;
    bool orto;
    glm::vec3 vrp,centre,obs,up,Pmin,Pmax,CentreBasePat;
};


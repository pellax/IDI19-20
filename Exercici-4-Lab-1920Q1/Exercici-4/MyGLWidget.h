#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include <QMouseEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <QRadioButton>
#include "model.h"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT
public slots:
    void TractaRadioButtonEscena();
    void TractaRadioButtonCamera();
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
    // mouse{Press/Release/Move}Event - Són cridades quan es realitza l'event 
    // corresponent de ratolí
    virtual void mousePressEvent (QMouseEvent *event);
    virtual void mouseReleaseEvent (QMouseEvent *event);
    virtual void mouseMoveEvent (QMouseEvent *event);

  private:
    void creaBuffersPatricio ();
    void creaBuffersTerra ();
    void creaBuffersPilota ();
    void carregaShaders ();
    void projectTransform ();
    void viewTransform ();
    void modelTransformTerra ();
    void modelTransformParet1 ();
    void modelTransformParet2 ();
    void modelTransformPatricio ();
    void modelTransformPilota ();
    void calculaCapsaModel (Model &p, float &escala, glm::vec3 &centreBase);
    void iniEscena ();
    void iniCamera ();
    void createBuffersLlum();
    void iniFocus ();
    void posicionaFocus ();
    QRadioButton* miradio;
    // VAO names
    GLuint VAO_Patr, VAO_Terra, VAO_Pil;
    // Program
    QOpenGLShaderProgram *program;
    // uniform locations
    GLuint transLoc, projLoc, viewLoc;
    // attribute locations
    GLuint vertexLoc, normalLoc, matambLoc, matdiffLoc, matspecLoc, matshinLoc,normalMatLoc,colFocusLoc,posFocusLoc,vertexSCOLoc;

    GLint ample, alt;
    glm::mat4 TG,View;
    // model
    Model patr, pil;
    // paràmetres calculats a partir de la capsa contenidora del model
    glm::vec3 centreBasePat, centreBasePil, posPilota;
    float escalaPat, escalaPil;

    glm::vec3 centreEsc;
    float radiEsc, ra, fov, zn, zf;

    float angleX, angleY,posFocusX,posFocusY;

    typedef  enum {NONE, ROTATE} InteractiveAction;
    InteractiveAction DoingInteractive;
    int xClick, yClick;
    bool F;
    signals:
        void EnviaEstat(const bool&);
	void setCheckCamera(const bool&);
	void setUnCheckCamera(const bool&);
	void setCheckEscena(const bool&);
	void setUnCheckEscena(const bool&);
};


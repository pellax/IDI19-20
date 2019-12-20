TEMPLATE    = app
QT         += opengl 

INCLUDEPATH += /dades/alejandro.jesus.capella.del/UltimoIDI/sessio4/bloc-2/exercici4/Model /usr/include/glm 

FORMS += MyForm.ui

HEADERS += MyForm.h MyGLWidget.h /dades/alejandro.jesus.capella.del/UltimoIDI/sessio4/bloc-2/exercici4/Model/model.h

SOURCES += /dades/alejandro.jesus.capella.del/UltimoIDI/sessio4/bloc-2/exercici4/Model/model.cpp main.cpp MyForm.cpp \
        MyGLWidget.cpp 

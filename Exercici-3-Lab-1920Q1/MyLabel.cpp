#include"MyLabel.h"
MyLabel::MyLabel(QWidget *parent=0):QLabel(parent)

{
	contrasenya = "";
	contrasenyarep = "";
}
void MyLabel::reset()
{
 contrasenya = "";
 contrasenyarep = "";
 setText(contrasenya);

}
void MyLabel::tractaContrasenya(QString s)

{
int compare;
contrasenya = s ;
compare = QString::compare(contrasenya,contrasenyarep,Qt::CaseSensitive);
if (compare == 0 && contrasenya.length() >= 6 )
	setStyleSheet("QLabel{background-color:green}");
else if (compare == 0 && contrasenya.length() < 6)

	setStyleSheet("QLabel{background-color:rgb(255,252,24);}");
else 
	setStyleSheet("QLabel{background-color:red}");
}
void MyLabel::tractaContrasenyarep(QString s)

{
int compare;
contrasenyarep = s;
compare = QString::compare(contrasenya,contrasenyarep,Qt::CaseSensitive);
if (compare == 0 && contrasenya.length() >= 6 )
	setStyleSheet("QLabel{background-color:green}");
else if (compare == 0 && contrasenya.length() < 6)

	setStyleSheet("QLabel{background-color:rgb(255,252,24);}");
else 
	setStyleSheet("QLabel{background-color:red}");
}
void MyLabel::setTextMajuscules(QString s)
{
QString str = s.toUpper();
setText(str);

}
void MyLabel:: actualitzaContrasenya(QString s)
{
    contrasenya = s;
}
void MyLabel::actualitzaContrasenyarep(QString s)
{
    contrasenyarep = s;
    
}

void MyLabel::tractaReturn()
{
int compare;
compare = QString::compare(contrasenya,contrasenyarep,Qt::CaseSensitive);

if (compare == 0 && contrasenya.length() >= 6 )
	setText("Contrasenya vàlida");
else if (compare == 0 && contrasenya.length() < 6)

	setText("Contrasenya de menys de 6 caràcters");

else 
	setText("Contrasenya no coincident");
}


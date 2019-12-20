#include"MyLabel.h"
MyLabel::MyLabel(QWidget *parent=0):QLabel(parent)

{
	label = "**********";
}
void MyLabel::reset()
{
 label = "**********";
 setText(label);
}
void MyLabel::setTextMajuscules(QString s)
{
QString str = s.toUpper();
setText(str);

}
void MyLabel::tractaLLetra(QString s)
{
    QChar c;
    QString str = "Diccionari";
    bool contain;
   contain = str.contains(s, Qt::CaseInsensitive);
   emit enviares(contain);
   s = s.toUpper();
   
    c = s.at(0);    
   switch(c.unicode()){
	case 'D':
		label.replace(0,1,"D");
		break;

	case 'I':
		label.replace(1,1,"i");
		label.replace(4,1,"i");
		label.replace(9,1,"i");
		break;
	case 'C':
		label.replace(2,2,"cc");
		break;
	case 'N':
		label.replace(6,1,"n");
		break;
	case 'A':
		label.replace(7,1,"a");
		break;
	case 'R':
		label.replace(8,1,"r");
		break;
	case 'O':
		label.replace(5,1,"o");
		break;
	default:
		break;

   
   }
   setText(label);

}


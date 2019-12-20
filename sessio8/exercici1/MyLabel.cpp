#include"MyLabel.h"
MyLabel::MyLabel(QWidget *parent=0):QLabel(parent)
{
 cotxes = 0;
 camions = 0;
 motos = 0;
 recaudacio = 0;
 total = 0;
}
void MyLabel::setTextMajuscules(QString s)
{
QString str = s.toUpper();
setText(str);

}
void MyLabel::addOneCar()
{
cotxes ++;
QString str = tr("%1").arg(cotxes);
setText(str);
			
}
void MyLabel::addOneTruck()
{

camions ++;
QString str = tr("%1").arg(camions);
setText(str);
			
}
void MyLabel::addOne()
{
total ++;
QString str = tr("%1").arg(total);
setText(str);
			
}
void MyLabel::addOneMoto()
{
motos ++;
QString str = tr("%1").arg(motos);
setText(str);
			

}
void MyLabel::setRecaudacioCar()
{
recaudacio++;
QString str = tr("%1").arg(recaudacio);

setText(str);
			

}
void MyLabel::setRecaudacioTruck()
{
recaudacio= recaudacio + 4;
QString str = tr("%1").arg(recaudacio);

setText(str);
			

}
void MyLabel::setRecaudacioMoto()
{
recaudacio++;
QString str = tr("%1").arg(recaudacio);

setText(str);
			

}


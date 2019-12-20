#include"MyLCD.h"
MyLCD::MyLCD(QWidget *parent):QLCDNumber(parent)
{
	contador = 5;
}
void MyLCD::restaUn()
{
	contador --;
	if (contador < 1 )contador = 0;
	display(contador);
}
void MyLCD::reset()
{
	contador = 5;
	display(contador);
}

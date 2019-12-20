#include<QLCDNumber>
class MyLCD:public QLCDNumber
{
	Q_OBJECT
	public:
	MyLCD(QWidget *parent);
	int contador;	
	public slots:
		void restaUn();
		void reset();

	signals:
};

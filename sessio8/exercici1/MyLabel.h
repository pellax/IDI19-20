#include<QLabel>
class MyLabel:public QLabel
{
	Q_OBJECT
	public: int cotxes,motos,camions,recaudacio,total;
		MyLabel(QWidget *parent);
	public slots:
		void setTextMajuscules(QString);
	        void addOneCar();
	        void addOneMoto();
	        void addOneTruck();
		void addOne();
		void setRecaudacioCar();
		void setRecaudacioMoto();
		void setRecaudacioTruck();
};

	

#include<QLabel>
class MyLabel:public QLabel
{
	Q_OBJECT
	public:
		MyLabel(QWidget *parent);
		QString contrasenya,contrasenyarep;		
	public slots:
		void reset();
		void setTextMajuscules(QString);
		void tractaContrasenya(QString s);
		void tractaContrasenyarep(QString s);
		void tractaReturn();
		void actualitzaContrasenya(QString s);
		void actualitzaContrasenyarep(QString s);
        signals:
                void enviares(const bool&);
};

	

#include<QLabel>
class MyLabel:public QLabel
{
	Q_OBJECT
	public:
		MyLabel(QWidget *parent);
		QString label;		
	public slots:
		void reset();
		void tractaLLetra(QString s);
		void setTextMajuscules(QString);
        signals:
                void enviares(const bool&);
};

	

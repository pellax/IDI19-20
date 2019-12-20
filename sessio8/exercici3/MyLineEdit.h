#include <QLineEdit>
class MyLineEdit:public QLineEdit
{
	Q_OBJECT
	public:
        MyLineEdit(QWidget *parent);
	public slots:
		void tractaReturn();
		void setBackground(bool contain);
      
	signals:
		void enviaText(const QString &);
		void restaun();
};

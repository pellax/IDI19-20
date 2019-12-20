#include"MyPushButton.h"
MyLabel::MyLabel(QWidget *parent = 0):QPushButton(parent)
				   
{

	seed =
}
void MyLabel()::tractaSenyal(int i)
{
	int opcio;
	 opcio = i % 4;
	 switch (opcio){
		 case 0:
			setStylesSheet("QPushButton{color:(247,191,190)}");
			break;
		 case 1:
			setStylesSheet("QPushButton{color:green}");
			break;
		 case 2:
			setStylesSheet("QPushButton{color:blue}");
			break;
		 case 3:
			setStylesSheet("QPushButton{color:(0,0,0)}");
			
				break;
		default : break;
	 }
}


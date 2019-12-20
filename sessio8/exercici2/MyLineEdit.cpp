#include"MyLineEdit.h"

MyLineEdit::MyLineEdit(QWidget *parent):QLineEdit(parent)
{
}

void MyLineEdit::tractaReturn()
{
    emit enviaText(text());
    clear();
}
void MyLineEdit::setBackground(bool contain)
{
//QLineEdit* pLabel = new QLineEdit;
if(contain)
{
setStyleSheet("QLineEdit{background-color:green}");
}
else
{
setStyleSheet("QLineEdit{background-color:red}");
emit restaun();
}
}

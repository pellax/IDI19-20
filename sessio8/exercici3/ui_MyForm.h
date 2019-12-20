/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <MyLCD.h>
#include <MyLabel.h>
#include <MyLineEdit.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    MyLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    MyLCD *lcdNumber;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    MyLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(MyForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new MyLineEdit(MyForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setInputMethodHints(Qt::ImhLowercaseOnly|Qt::ImhUppercaseOnly);

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lcdNumber = new MyLCD(MyForm);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setProperty("value", QVariant(5));
        lcdNumber->setProperty("intValue", QVariant(5));

        horizontalLayout->addWidget(lcdNumber);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(MyForm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new MyLabel(MyForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setTextFormat(Qt::PlainText);
        label_2->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(MyForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MyForm);
        QObject::connect(label_2, SIGNAL(enviares(bool)), lineEdit, SLOT(setBackground(bool)));
        QObject::connect(pushButton, SIGNAL(clicked()), lcdNumber, SLOT(reset()));
        QObject::connect(lineEdit, SIGNAL(restaun()), lcdNumber, SLOT(restaUn()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), lineEdit, SLOT(clear()));
        QObject::connect(lineEdit, SIGNAL(returnPressed()), lineEdit, SLOT(tractaReturn()));
        QObject::connect(lineEdit, SIGNAL(enviaText(QString)), label_2, SLOT(tractaLLetra(QString)));
        QObject::connect(pushButton, SIGNAL(clicked()), label_2, SLOT(reset()));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", Q_NULLPTR));
        lineEdit->setInputMask(QApplication::translate("MyForm", "aaaaa; ", Q_NULLPTR));
        label->setText(QApplication::translate("MyForm", "Paraula", Q_NULLPTR));
        label_2->setText(QApplication::translate("MyForm", "**********", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyForm", "Neteja", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MyForm", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H

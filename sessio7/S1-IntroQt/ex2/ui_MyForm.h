/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_3;
    QLabel *label_3;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QString::fromUtf8("MyForm"));
        MyForm->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(MyForm);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton = new QRadioButton(MyForm);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);

        label = new QLabel(MyForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 1, 1);"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_2 = new QRadioButton(MyForm);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_2->addWidget(radioButton_2);

        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 255, 9);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_3 = new QRadioButton(MyForm);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout_3->addWidget(radioButton_3);

        label_3 = new QLabel(MyForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 9, 238);"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MyForm);
        QObject::connect(radioButton, SIGNAL(clicked(bool)), label_2, SLOT(setDisabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), label_3, SLOT(setDisabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), label, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), label, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), label_2, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), label_3, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_3, SIGNAL(clicked(bool)), label, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_3, SIGNAL(clicked(bool)), label_2, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_3, SIGNAL(clicked(bool)), label_3, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MyForm", "Vermell", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MyForm", "VERMELL", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MyForm", "Verd", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MyForm", "VERD", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MyForm", "Blau", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MyForm", "BLAU", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H

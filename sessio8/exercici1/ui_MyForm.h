/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <MyLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *radioButton_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    MyLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    MyLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    MyLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    MyLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_7;
    MyLabel *label_7;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(638, 406);
        MyForm->setStyleSheet(QLatin1String("QRadioButton::indicator:checked {\n"
"    background-color:       green;\n"
"    border:                 2px solid white;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       black;\n"
"    border:                 2px solid white;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(MyForm);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton = new QRadioButton(MyForm);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setEnabled(true);
        radioButton->setStyleSheet(QLatin1String("\n"
"QRadioButton::indicator:checked {\n"
"    background-color:       green;\n"
"    border : solid black\n"
"\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       black;\n"
"   border: solid black\n"
"\n"
"}"));
        radioButton->setChecked(true);

        verticalLayout_3->addWidget(radioButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        radioButton_2 = new QRadioButton(MyForm);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setEnabled(true);
        radioButton_2->setStyleSheet(QLatin1String("\n"
"QRadioButton::indicator:checked {\n"
"    background-color:       red;\n"
"   border: solid black\n"
"\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       white;\n"
"    border:solid black\n"
"}"));

        verticalLayout_3->addWidget(radioButton_2);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_6);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new MyLabel(MyForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(MyForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_4 = new MyLabel(MyForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_3 = new QPushButton(MyForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_5 = new MyLabel(MyForm);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(MyForm);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_3 = new MyLabel(MyForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(MyForm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        label_7 = new MyLabel(MyForm);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        retranslateUi(MyForm);
        QObject::connect(pushButton, SIGNAL(clicked()), label_2, SLOT(addOneCar()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_4, SLOT(addOneMoto()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), label_5, SLOT(addOneTruck()));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton, SLOT(setEnabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_2, SLOT(setEnabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_3, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_2, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_3, SLOT(setDisabled(bool)));
        QObject::connect(pushButton, SIGNAL(clicked()), label_3, SLOT(addOne()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_3, SLOT(addOne()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), label_3, SLOT(addOne()));
        QObject::connect(pushButton, SIGNAL(clicked()), label_7, SLOT(setRecaudacioCar()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_7, SLOT(setRecaudacioMoto()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), label_7, SLOT(setRecaudacioTruck()));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MyForm", "Obert", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MyForm", "Tancat", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyForm", "Cotxes", Q_NULLPTR));
        label_2->setText(QApplication::translate("MyForm", "0", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MyForm", "Motos", Q_NULLPTR));
        label_4->setText(QApplication::translate("MyForm", "0", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MyForm", "Camions", Q_NULLPTR));
        label_5->setText(QApplication::translate("MyForm", "0", Q_NULLPTR));
        label_6->setText(QApplication::translate("MyForm", "Total", Q_NULLPTR));
        label_3->setText(QApplication::translate("MyForm", "0", Q_NULLPTR));
        label->setText(QApplication::translate("MyForm", "Recaudaci\303\263", Q_NULLPTR));
        label_7->setText(QApplication::translate("MyForm", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H

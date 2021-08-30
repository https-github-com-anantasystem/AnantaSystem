/********************************************************************************
** Form generated from reading UI file 'removemessage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEMESSAGE_H
#define UI_REMOVEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_removemessage
{
public:
    QGridLayout *gridLayout;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *afichagenbclient;

    void setupUi(QDialog *removemessage)
    {
        if (removemessage->objectName().isEmpty())
            removemessage->setObjectName(QString::fromUtf8("removemessage"));
        removemessage->resize(339, 113);
        gridLayout = new QGridLayout(removemessage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinBox = new QSpinBox(removemessage);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(10000);
        spinBox->setValue(100);

        gridLayout->addWidget(spinBox, 2, 1, 1, 1);

        pushButton = new QPushButton(removemessage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(removemessage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 1);

        label_2 = new QLabel(removemessage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 3);

        afichagenbclient = new QLabel(removemessage);
        afichagenbclient->setObjectName(QString::fromUtf8("afichagenbclient"));

        gridLayout->addWidget(afichagenbclient, 0, 0, 1, 3);


        retranslateUi(removemessage);

        QMetaObject::connectSlotsByName(removemessage);
    } // setupUi

    void retranslateUi(QDialog *removemessage)
    {
        removemessage->setWindowTitle(QCoreApplication::translate("removemessage", "Dialog", nullptr));
        spinBox->setSuffix(QCoreApplication::translate("removemessage", " messages", nullptr));
        pushButton->setText(QCoreApplication::translate("removemessage", "10", nullptr));
        pushButton_2->setText(QCoreApplication::translate("removemessage", "tout suprim\303\251e", nullptr));
        label_2->setText(QCoreApplication::translate("removemessage", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">combien voulez vous en suprimer ?</span></p></body></html>", nullptr));
        afichagenbclient->setText(QCoreApplication::translate("removemessage", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">il y a &quot;non resegner &quot; messages</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class removemessage: public Ui_removemessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEMESSAGE_H

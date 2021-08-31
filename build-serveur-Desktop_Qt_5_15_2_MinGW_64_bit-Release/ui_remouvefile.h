/********************************************************************************
** Form generated from reading UI file 'remouvefile.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOUVEFILE_H
#define UI_REMOUVEFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_remouveFile
{
public:
    QGridLayout *gridLayout;
    QPushButton *deleteAllMessage;
    QSpinBox *deleteNMessage;
    QLabel *TextLabeldisplayingNumberDessage;
    QLabel *label_2;
    QPushButton *delete10message;

    void setupUi(QDialog *remouveFile)
    {
        if (remouveFile->objectName().isEmpty())
            remouveFile->setObjectName(QString::fromUtf8("remouveFile"));
        remouveFile->resize(350, 113);
        gridLayout = new QGridLayout(remouveFile);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        deleteAllMessage = new QPushButton(remouveFile);
        deleteAllMessage->setObjectName(QString::fromUtf8("deleteAllMessage"));

        gridLayout->addWidget(deleteAllMessage, 2, 2, 1, 1);

        deleteNMessage = new QSpinBox(remouveFile);
        deleteNMessage->setObjectName(QString::fromUtf8("deleteNMessage"));
        deleteNMessage->setMaximum(10000);

        gridLayout->addWidget(deleteNMessage, 2, 1, 1, 1);

        TextLabeldisplayingNumberDessage = new QLabel(remouveFile);
        TextLabeldisplayingNumberDessage->setObjectName(QString::fromUtf8("TextLabeldisplayingNumberDessage"));

        gridLayout->addWidget(TextLabeldisplayingNumberDessage, 0, 0, 1, 3);

        label_2 = new QLabel(remouveFile);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 3);

        delete10message = new QPushButton(remouveFile);
        delete10message->setObjectName(QString::fromUtf8("delete10message"));

        gridLayout->addWidget(delete10message, 2, 0, 1, 1);


        retranslateUi(remouveFile);

        QMetaObject::connectSlotsByName(remouveFile);
    } // setupUi

    void retranslateUi(QDialog *remouveFile)
    {
        remouveFile->setWindowTitle(QCoreApplication::translate("remouveFile", "Dialog", nullptr));
        deleteAllMessage->setText(QCoreApplication::translate("remouveFile", "tout les message", nullptr));
        deleteNMessage->setSuffix(QCoreApplication::translate("remouveFile", " messages", nullptr));
        TextLabeldisplayingNumberDessage->setText(QCoreApplication::translate("remouveFile", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">il y a &quot;non defini&quot; message</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("remouveFile", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">combien voulez vous en suprimer</span></p></body></html>", nullptr));
        delete10message->setText(QCoreApplication::translate("remouveFile", "10 message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class remouveFile: public Ui_remouveFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOUVEFILE_H

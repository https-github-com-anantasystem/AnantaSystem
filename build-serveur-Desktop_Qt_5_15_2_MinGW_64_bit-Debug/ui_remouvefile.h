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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_remouveFile
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *delete10message;
    QSpinBox *deleteNMessage;
    QPushButton *deleteAllMessage;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *TextLabeldisplayingNumberDessage;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *remouveFile)
    {
        if (remouveFile->objectName().isEmpty())
            remouveFile->setObjectName(QString::fromUtf8("remouveFile"));
        remouveFile->resize(352, 119);
        gridLayout = new QGridLayout(remouveFile);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        delete10message = new QPushButton(remouveFile);
        delete10message->setObjectName(QString::fromUtf8("delete10message"));

        gridLayout_2->addWidget(delete10message, 0, 0, 1, 1);

        deleteNMessage = new QSpinBox(remouveFile);
        deleteNMessage->setObjectName(QString::fromUtf8("deleteNMessage"));
        deleteNMessage->setMaximum(10000);

        gridLayout_2->addWidget(deleteNMessage, 0, 1, 1, 1);

        deleteAllMessage = new QPushButton(remouveFile);
        deleteAllMessage->setObjectName(QString::fromUtf8("deleteAllMessage"));

        gridLayout_2->addWidget(deleteAllMessage, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 3, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(remouveFile);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 2, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        TextLabeldisplayingNumberDessage = new QLabel(remouveFile);
        TextLabeldisplayingNumberDessage->setObjectName(QString::fromUtf8("TextLabeldisplayingNumberDessage"));

        horizontalLayout->addWidget(TextLabeldisplayingNumberDessage);

        pushButton = new QPushButton(remouveFile);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Refresh_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 2);


        gridLayout->addLayout(gridLayout_3, 0, 0, 1, 2);


        retranslateUi(remouveFile);

        QMetaObject::connectSlotsByName(remouveFile);
    } // setupUi

    void retranslateUi(QDialog *remouveFile)
    {
        remouveFile->setWindowTitle(QCoreApplication::translate("remouveFile", "Dialog", nullptr));
        delete10message->setText(QCoreApplication::translate("remouveFile", "10 message", nullptr));
        deleteNMessage->setSuffix(QCoreApplication::translate("remouveFile", " messages", nullptr));
        deleteAllMessage->setText(QCoreApplication::translate("remouveFile", "tout les message", nullptr));
        label_2->setText(QCoreApplication::translate("remouveFile", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">combien voulez vous en suprimer</span></p></body></html>", nullptr));
        TextLabeldisplayingNumberDessage->setText(QCoreApplication::translate("remouveFile", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">il y a &quot;non defini&quot; message</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("remouveFile", "sycroniser", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class remouveFile: public Ui_remouveFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOUVEFILE_H

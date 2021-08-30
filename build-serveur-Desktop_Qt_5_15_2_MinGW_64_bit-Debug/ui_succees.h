/********************************************************************************
** Form generated from reading UI file 'succees.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCEES_H
#define UI_SUCCEES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sucees
{
public:
    QGridLayout *gridLayout;
    QLabel *nbmessage;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_4;
    QPushButton *message100;
    QPushButton *message1000;
    QFrame *line;
    QLabel *label_2;
    QPushButton *message10;
    QLabel *label_6;
    QPushButton *messagemaxint;
    QFrame *line_2;
    QLabel *label;
    QLabel *label_3;
    QFrame *line_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QCheckBox *saveNbMessage;
    QPushButton *pushButton_2;

    void setupUi(QDialog *sucees)
    {
        if (sucees->objectName().isEmpty())
            sucees->setObjectName(QString::fromUtf8("sucees"));
        sucees->resize(377, 383);
        gridLayout = new QGridLayout(sucees);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nbmessage = new QLabel(sucees);
        nbmessage->setObjectName(QString::fromUtf8("nbmessage"));

        gridLayout->addWidget(nbmessage, 0, 0, 1, 1);

        groupBox = new QGroupBox(sucees);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 5, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        message100 = new QPushButton(groupBox);
        message100->setObjectName(QString::fromUtf8("message100"));
        message100->setFlat(true);

        gridLayout_2->addWidget(message100, 3, 2, 1, 1);

        message1000 = new QPushButton(groupBox);
        message1000->setObjectName(QString::fromUtf8("message1000"));
        message1000->setFlat(true);

        gridLayout_2->addWidget(message1000, 4, 2, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 2, 1, 4, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        message10 = new QPushButton(groupBox);
        message10->setObjectName(QString::fromUtf8("message10"));
        message10->setFlat(true);

        gridLayout_2->addWidget(message10, 2, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        messagemaxint = new QPushButton(groupBox);
        messagemaxint->setObjectName(QString::fromUtf8("messagemaxint"));
        messagemaxint->setFlat(true);

        gridLayout_2->addWidget(messagemaxint, 5, 2, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 1, 0, 1, 3);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(sucees);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 0, 1, 1);

        saveNbMessage = new QCheckBox(groupBox_2);
        saveNbMessage->setObjectName(QString::fromUtf8("saveNbMessage"));
        saveNbMessage->setChecked(true);

        gridLayout_3->addWidget(saveNbMessage, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);


        retranslateUi(sucees);

        QMetaObject::connectSlotsByName(sucees);
    } // setupUi

    void retranslateUi(QDialog *sucees)
    {
        sucees->setWindowTitle(QCoreApplication::translate("sucees", "les suc\303\251es", nullptr));
        nbmessage->setText(QCoreApplication::translate("sucees", "le monbre de tes message : non resgner", nullptr));
        groupBox->setTitle(QCoreApplication::translate("sucees", "suc\303\251es :", nullptr));
        label_8->setText(QCoreApplication::translate("sucees", "fait pet\303\251 le int", nullptr));
        label_4->setText(QCoreApplication::translate("sucees", "s'est converser", nullptr));
#if QT_CONFIG(tooltip)
        message100->setToolTip(QCoreApplication::translate("sucees", "il vous faut 100 message", nullptr));
#endif // QT_CONFIG(tooltip)
        message100->setText(QCoreApplication::translate("sucees", "100 messages", nullptr));
#if QT_CONFIG(tooltip)
        message1000->setToolTip(QCoreApplication::translate("sucees", "il vous faut 1000 message", nullptr));
#endif // QT_CONFIG(tooltip)
        message1000->setText(QCoreApplication::translate("sucees", "1 000 messages", nullptr));
        label_2->setText(QCoreApplication::translate("sucees", "a trouver le bouton envoyer", nullptr));
#if QT_CONFIG(tooltip)
        message10->setToolTip(QCoreApplication::translate("sucees", "il vous faut 10 message", nullptr));
#endif // QT_CONFIG(tooltip)
        message10->setText(QCoreApplication::translate("sucees", "10 messages", nullptr));
        label_6->setText(QCoreApplication::translate("sucees", "un boss", nullptr));
#if QT_CONFIG(tooltip)
        messagemaxint->setToolTip(QCoreApplication::translate("sucees", "il vous faut 2 147 483 647  message", nullptr));
#endif // QT_CONFIG(tooltip)
        messagemaxint->setText(QCoreApplication::translate("sucees", "2 147 483 647 messages", nullptr));
        label->setText(QCoreApplication::translate("sucees", "nom du succes", nullptr));
        label_3->setText(QCoreApplication::translate("sucees", "etat du succes", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("sucees", "parametre des succ\303\251s", nullptr));
        pushButton->setText(QCoreApplication::translate("sucees", "generer ma clef de de syconysation", nullptr));
        saveNbMessage->setText(QCoreApplication::translate("sucees", "enrregistrer le nombre de message", nullptr));
        pushButton_2->setText(QCoreApplication::translate("sucees", "suprimer le nombre de message enregistrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sucees: public Ui_sucees {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCEES_H

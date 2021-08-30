/********************************************************************************
** Form generated from reading UI file 'parametre.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETRE_H
#define UI_PARAMETRE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_parametre
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *deletbuton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label;
    QComboBox *comboBox_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkboxmodecondensee;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QPushButton *site;
    QPushButton *discord;
    QPushButton *tweter;
    QPushButton *don;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_3;
    QLabel *label_3;

    void setupUi(QDialog *parametre)
    {
        if (parametre->objectName().isEmpty())
            parametre->setObjectName(QString::fromUtf8("parametre"));
        parametre->resize(369, 699);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Fichier_4.png"), QSize(), QIcon::Normal, QIcon::Off);
        parametre->setWindowIcon(icon);
        gridLayout = new QGridLayout(parametre);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(parametre);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setChecked(true);

        gridLayout_4->addWidget(checkBox_3, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/analyse.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);

        gridLayout_4->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/Blue_question_mark_icon.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon2);
        pushButton_5->setFlat(true);

        gridLayout_4->addWidget(pushButton_5, 2, 1, 1, 1);

        deletbuton = new QPushButton(groupBox_3);
        deletbuton->setObjectName(QString::fromUtf8("deletbuton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/suprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        deletbuton->setIcon(icon3);

        gridLayout_4->addWidget(deletbuton, 1, 0, 1, 2);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(parametre);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_3->addWidget(comboBox_2, 0, 1, 1, 2);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout_3->addWidget(comboBox_3, 1, 1, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setIcon(icon2);
        pushButton->setFlat(true);

        gridLayout_3->addWidget(pushButton, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setIcon(icon2);
        pushButton_2->setFlat(true);

        gridLayout_3->addWidget(pushButton_2, 2, 2, 1, 1);

        checkboxmodecondensee = new QCheckBox(groupBox_2);
        checkboxmodecondensee->setObjectName(QString::fromUtf8("checkboxmodecondensee"));
        checkboxmodecondensee->setChecked(true);

        gridLayout_3->addWidget(checkboxmodecondensee, 2, 0, 1, 2);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(parametre);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        site = new QPushButton(groupBox_4);
        site->setObjectName(QString::fromUtf8("site"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/Anantasite.png"), QSize(), QIcon::Normal, QIcon::Off);
        site->setIcon(icon4);

        gridLayout_5->addWidget(site, 0, 0, 1, 1);

        discord = new QPushButton(groupBox_4);
        discord->setObjectName(QString::fromUtf8("discord"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/discord logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        discord->setIcon(icon5);

        gridLayout_5->addWidget(discord, 1, 0, 1, 1);

        tweter = new QPushButton(groupBox_4);
        tweter->setObjectName(QString::fromUtf8("tweter"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/Twitter_bird_logo_2012.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        tweter->setIcon(icon6);

        gridLayout_5->addWidget(tweter, 2, 0, 1, 1);

        don = new QPushButton(groupBox_4);
        don->setObjectName(QString::fromUtf8("don"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/image0.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        don->setIcon(icon7);

        gridLayout_5->addWidget(don, 3, 0, 1, 1);


        gridLayout->addWidget(groupBox_4, 4, 0, 1, 1);

        groupBox = new QGroupBox(parametre);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setChecked(true);

        gridLayout_2->addWidget(checkBox_2, 1, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        gridLayout_2->addWidget(checkBox, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(parametre);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_3 = new QPushButton(groupBox_5);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/success.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon8);

        gridLayout_6->addWidget(pushButton_3, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_6->addWidget(label_3, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_5, 3, 0, 1, 1);


        retranslateUi(parametre);

        QMetaObject::connectSlotsByName(parametre);
    } // setupUi

    void retranslateUi(QDialog *parametre)
    {
        parametre->setWindowTitle(QCoreApplication::translate("parametre", "parametre", nullptr));
#if QT_CONFIG(statustip)
        parametre->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        parametre->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        parametre->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        groupBox_3->setTitle(QCoreApplication::translate("parametre", "serveur", nullptr));
        checkBox_3->setText(QCoreApplication::translate("parametre", "sauvgarder les message", nullptr));
        pushButton_4->setText(QCoreApplication::translate("parametre", "faire un recapitulatif (mode debug)", nullptr));
        pushButton_5->setText(QString());
        deletbuton->setText(QCoreApplication::translate("parametre", "suprimer des message enregistrer", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("parametre", "interface", nullptr));
        label_2->setText(QCoreApplication::translate("parametre", "theme", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("parametre", "francais", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("parametre", "anglais", nullptr));

        label->setText(QCoreApplication::translate("parametre", "langue", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("parametre", "blanc", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("parametre", "noir", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("parametre", "Schtroumpfs", nullptr));

        pushButton->setText(QString());
        pushButton_2->setText(QString());
        checkboxmodecondensee->setText(QCoreApplication::translate("parametre", "activer la transparence du mode condens\303\251e", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("parametre", "contact", nullptr));
        site->setText(QCoreApplication::translate("parametre", "le site", nullptr));
        discord->setText(QCoreApplication::translate("parametre", "le discord (aide/bug/probleme de traduction)", nullptr));
        tweter->setText(QCoreApplication::translate("parametre", "le twiter", nullptr));
        don->setText(QCoreApplication::translate("parametre", "faire un don", nullptr));
        groupBox->setTitle(QCoreApplication::translate("parametre", "notification", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_2->setToolTip(QCoreApplication::translate("parametre", "permet de definire lactivation des notification visuelle", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        checkBox_2->setWhatsThis(QCoreApplication::translate("parametre", "permet de definire lactivation des notification visuelle", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        checkBox_2->setAccessibleDescription(QCoreApplication::translate("parametre", "permet de definire lactivation des notification visuelle", nullptr));
#endif // QT_CONFIG(accessibility)
        checkBox_2->setText(QCoreApplication::translate("parametre", "notification visuelle", nullptr));
#if QT_CONFIG(tooltip)
        checkBox->setToolTip(QCoreApplication::translate("parametre", "permet de definire lactivation des notification sonore", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        checkBox->setAccessibleDescription(QCoreApplication::translate("parametre", "permet de definire lactivation des notification sonore", nullptr));
#endif // QT_CONFIG(accessibility)
        checkBox->setText(QCoreApplication::translate("parametre", "notification sonore", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("parametre", "son par default", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("parametre", "blup blup", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("parametre", "selectioner une musique", nullptr));

        groupBox_5->setTitle(QCoreApplication::translate("parametre", "suc\303\251es", nullptr));
        pushButton_3->setText(QCoreApplication::translate("parametre", "voir mes suc\303\251e", nullptr));
        label_3->setText(QCoreApplication::translate("parametre", "nombre de message :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class parametre: public Ui_parametre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRE_H

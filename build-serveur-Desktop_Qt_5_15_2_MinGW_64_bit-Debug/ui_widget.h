/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *messagelist;
    QGridLayout *gridLayout_4;
    QSpinBox *serveurport;
    QLineEdit *serveurip;
    QLabel *label_5;
    QLabel *label_4;
    QPushButton *parametrebuton;
    QListWidget *clientlist;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_psedo;
    QLineEdit *psedo;
    QLabel *label_message_3;
    QLineEdit *mesage;
    QPushButton *sentbuton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(681, 418);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Ananta.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messagelist = new QTextBrowser(Widget);
        messagelist->setObjectName(QString::fromUtf8("messagelist"));

        gridLayout->addWidget(messagelist, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        serveurport = new QSpinBox(Widget);
        serveurport->setObjectName(QString::fromUtf8("serveurport"));
        serveurport->setMaximumSize(QSize(16777215, 16777215));
        serveurport->setMinimum(1024);
        serveurport->setMaximum(65535);
        serveurport->setValue(2048);

        gridLayout_4->addWidget(serveurport, 2, 1, 1, 1);

        serveurip = new QLineEdit(Widget);
        serveurip->setObjectName(QString::fromUtf8("serveurip"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(serveurip->sizePolicy().hasHeightForWidth());
        serveurip->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(serveurip, 1, 1, 1, 1);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 2, 0, 1, 1);

        parametrebuton = new QPushButton(Widget);
        parametrebuton->setObjectName(QString::fromUtf8("parametrebuton"));
        parametrebuton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(parametrebuton, 3, 0, 1, 2);

        clientlist = new QListWidget(Widget);
        clientlist->setObjectName(QString::fromUtf8("clientlist"));

        gridLayout_4->addWidget(clientlist, 4, 0, 1, 2);


        gridLayout->addLayout(gridLayout_4, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_psedo = new QLabel(Widget);
        label_psedo->setObjectName(QString::fromUtf8("label_psedo"));

        horizontalLayout_3->addWidget(label_psedo);

        psedo = new QLineEdit(Widget);
        psedo->setObjectName(QString::fromUtf8("psedo"));

        horizontalLayout_3->addWidget(psedo, 0, Qt::AlignLeft);

        label_message_3 = new QLabel(Widget);
        label_message_3->setObjectName(QString::fromUtf8("label_message_3"));

        horizontalLayout_3->addWidget(label_message_3);

        mesage = new QLineEdit(Widget);
        mesage->setObjectName(QString::fromUtf8("mesage"));

        horizontalLayout_3->addWidget(mesage);

        sentbuton = new QPushButton(Widget);
        sentbuton->setObjectName(QString::fromUtf8("sentbuton"));
        sentbuton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/sent.png"), QSize(), QIcon::Normal, QIcon::Off);
        sentbuton->setIcon(icon1);

        horizontalLayout_3->addWidget(sentbuton);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 2);


        retranslateUi(Widget);
        QObject::connect(mesage, SIGNAL(returnPressed()), sentbuton, SLOT(animateClick()));
        QObject::connect(sentbuton, SIGNAL(clicked()), mesage, SLOT(setFocus()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "ananta systeme tchat", nullptr));
        messagelist->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        serveurip->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "conn\303\251ct\303\251 a :", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "mot de passe", nullptr));
        parametrebuton->setText(QCoreApplication::translate("Widget", "parametre", nullptr));
        label_psedo->setText(QCoreApplication::translate("Widget", "psedo", nullptr));
        label_message_3->setText(QCoreApplication::translate("Widget", "message", nullptr));
        sentbuton->setText(QCoreApplication::translate("Widget", "envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

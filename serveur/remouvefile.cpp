#include "remouvefile.h"
#include "ui_remouvefile.h"

remouveFile::remouveFile(QList<QMap<QString, QString>> &ref, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remouveFile)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    listeOfMessage =new QList<QMap<QString, QString>>;
    listeOfMessage = &ref;
    ui->TextLabeldisplayingNumberDessage->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">il y a "+QString::number(listeOfMessage->size())+" message</span></p></body></html>");
    ui->deleteNMessage->setMaximum(listeOfMessage->size());
}
remouveFile::~remouveFile()
{
    delete ui;
}

void remouveFile::on_delete10message_clicked()
{
    for (int compteur {10}; compteur > 0; --compteur)
    {
       if(listeOfMessage->isEmpty()){listeOfMessage->removeFirst();}
    }
    ui->TextLabeldisplayingNumberDessage->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">il y a "+QString::number(listeOfMessage->size())+" message</span></p></body></html>");
    ui->deleteNMessage->setMaximum(listeOfMessage->size());
}


void remouveFile::on_deleteAllMessage_clicked()
{
    listeOfMessage->clear();
    ui->TextLabeldisplayingNumberDessage->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">il y a "+QString::number(listeOfMessage->size())+" message</span></p></body></html>");
    ui->deleteNMessage->setMaximum(listeOfMessage->size());
}
void remouveFile::on_deleteNMessage_editingFinished()
{
    for (int compteur {ui->deleteNMessage->value()}; compteur > 0; --compteur)
    {
        if(listeOfMessage->isEmpty()){listeOfMessage->removeFirst();}
    }
    ui->TextLabeldisplayingNumberDessage->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">il y a "+QString::number(listeOfMessage->size())+" message</span></p></body></html>");
    ui->deleteNMessage->setMaximum(listeOfMessage->size());
}
void remouveFile::on_pushButton_clicked()
{
    ui->TextLabeldisplayingNumberDessage->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">il y a "+QString::number(listeOfMessage->size())+" message</span></p></body></html>");
    ui->deleteNMessage->setMaximum(listeOfMessage->size());
}


#include "succees.h"
#include "ui_succees.h"

sucees::sucees(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sucees)
{
    ui->setupUi(this);
    settings = new QSettings("ananta system","tchat 4.1",this);
    ui->saveNbMessage->setChecked(settings->value("succes/succes").toBool());
    ui->nbmessage->setText("le monbre de tes message :"+QString::number(settings->value("succes/nbmessage").toInt()));
    if(settings->value("succes/nbmessage").toInt()<0&&settings->value("succes/succes").toBool()==true){
        QMessageBox::critical(this,tr("tchit detecter"),tr("alors comme ca on veut avoir des sucée gratuis ? c'est mal de tricher"));
        ui->message10->setToolTip("imposible de l'avoir vous avez tricher");
        ui->message100->setToolTip("imposible de l'avoir vous avez tricher");
        ui->message1000->setToolTip("imposible de l'avoir vous avez tricher");
        ui->messagemaxint->setToolTip("imposible de l'avoir vous avez tricher");
        ui->message10->setText("");
        ui->message100->setText("");
        ui->message1000->setText("");
        ui->messagemaxint->setText("");
        ui->message10->setIcon(QIcon(":/image/suprimer.png"));
        ui->message100->setIcon(QIcon(":/image/suprimer.png"));
        ui->message1000->setIcon(QIcon(":/image/suprimer.png"));
        ui->messagemaxint->setIcon(QIcon(":/image/suprimer.png"));
    }if(settings->value("succes/nbmessage").toInt()<0&&settings->value("succes/succes").toBool()==false){
        ui->message10->setToolTip("imposible de l'avoir vous avez desactiver les succés");
        ui->message100->setToolTip("imposible de l'avoir vous avez desactiver les succés");
        ui->message1000->setToolTip("imposible de l'avoir vous avez desactiver les succés");
        ui->messagemaxint->setToolTip("imposible de l'avoir vous avez desactiver les succés");
        ui->message10->setText("");
        ui->message100->setText("");
        ui->message1000->setText("");
        ui->messagemaxint->setText("");
        ui->message10->setIcon(QIcon(":/image/suprimer.png"));
        ui->message100->setIcon(QIcon(":/image/suprimer.png"));
        ui->message1000->setIcon(QIcon(":/image/suprimer.png"));
        ui->messagemaxint->setIcon(QIcon(":/image/suprimer.png"));
    }if(settings->value("succes/nbmessage").toInt()>=10){
        ui->message10->setToolTip("obtenus");
        ui->message10->setText("");
        ui->message10->setIcon(QIcon(":/image/Check_green.png"));
    }if(settings->value("succes/nbmessage").toInt()>=100){
        ui->message100->setToolTip("obtenus");
        ui->message100->setText("");
        ui->message100->setIcon(QIcon(":/image/Check_green.png"));
    } if(settings->value("succes/nbmessage").toInt()>=1000){
        ui->message1000->setToolTip("obtenus");
        ui->message1000->setText("");
        ui->message1000->setIcon(QIcon(":/image/Check_green.png"));
    } if(settings->value("succes/nbmessage").toInt()>=2147483647){
        ui->messagemaxint->setToolTip("obtenus");
        ui->messagemaxint->setText("");
        ui->messagemaxint->setIcon(QIcon(":/image/Check_green.png"));
    }
}
sucees::~sucees()
{
    delete ui;
}
void sucees::on_message10_clicked()
{
    if(settings->value("succes/nbmessage").toInt()<=10&&settings->value("succes/nbmessage").toInt()>0){
        QMessageBox::information(this,tr("info"),tr("pour avoir ce succé il faux avoir envoyer 10 message"));
    }else if(settings->value("succes/nbmessage").toInt()>=10){
        QMessageBox::information(this,tr("info"),tr("vous avez reusis a avoir ce succée"));
    }
}
void sucees::on_message100_clicked()
{
    if(settings->value("succes/nbmessage").toInt()<=100&&settings->value("succes/nbmessage").toInt()>0){
        QMessageBox::information(this,tr("info"),tr("pour avoir ce succé il faux avoir envoyer 100 message"));
    }else if(settings->value("succes/nbmessage").toInt()>=100){
        QMessageBox::information(this,tr("info"),tr("vous avez reusis a avoir ce succée"));
    }
}
void sucees::on_message1000_clicked()
{
    if(settings->value("succes/nbmessage").toInt()<=1000&&settings->value("succes/nbmessage").toInt()>0){
        QMessageBox::information(this,tr("info"),tr("pour avoir ce succé il faux avoir envoyer 1000 message"));
    }else if(settings->value("succes/nbmessage").toInt()>=1000){
        QMessageBox::information(this,tr("info"),tr("vous avez reusis a avoir ce succée"));
    }
}
void sucees::on_messagemaxint_clicked()
{
    if(settings->value("succes/nbmessage").toInt()<=2147483647 &&settings->value("succes/nbmessage").toInt()>0){
        QMessageBox::information(this,tr("info"),tr("pour avoir ce succé il faux avoir envoyer 2 147 483 647 message"));
    }else if(settings->value("succes/nbmessage").toInt()>=2147483647){
        QMessageBox::information(this,tr("info"),tr("vous avez reusis a avoir ce succée"));
    }
}
void sucees::on_saveNbMessage_toggled(bool checked)
{
    settings->setValue("succes/succes",checked);
}
void sucees::on_pushButton_2_clicked()
{
    settings->setValue("succes/nbmessage",0);
    QMessageBox::critical(this,tr("supression prise en compte"),tr("la supression du nombre de message a bien fonctionée vous avez actuellement 0 message"));
}

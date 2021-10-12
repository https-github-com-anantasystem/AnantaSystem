#include "succees.h"
#include "ui_succees.h"

sucees::sucees(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sucees)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    settings = new QSettings("Ananta System","Tchat",this);
    ui->saveNbMessage->setChecked(settings->value("succes/succes").toBool());
    ui->nbmessage->setText("Nombre de messages envoyés :"+QString::number(settings->value("succes/nbmessage").toInt()));
    if(settings->value("succes/nbmessage").toInt()<0&&settings->value("succes/succes").toBool()){
        QMessageBox::critical(this,tr("Cheat détecté"),tr("Alors comme ça, on veut avoir des succès gratuits ? C'est mal de tricher !"));
        ui->message10->setToolTip("Impossible de l'obtenir, vous avez triché!");
        ui->message100->setToolTip("Impossible de l'obtenir, vous avez triché!");
        ui->message1000->setToolTip("Impossible de l'obtenir, vous avez triché!");
        ui->messagemaxint->setToolTip("Impossible de l'obtenir, vous avez triché!");
        ui->userdifferent10->setToolTip("Impossible de l'obtenir, vous avez triché!");
        ui->userdifferent30->setToolTip("Impossible de l'obtenir, vous avez triché!");
        ui->userdifferent100->setToolTip("Impossible de l'obtenir, vous avez triché!");
        ui->server20->setToolTip("Impossible de l'obtenir, vous avez triché!");
        ui->message10->setText("");
        ui->message100->setText("");
        ui->message1000->setText("");
        ui->messagemaxint->setText("");
        ui->userdifferent10->setText("");
        ui->userdifferent30->setText("");
        ui->userdifferent100->setText("");
        ui->server20->setText("");
        ui->message10->setIcon(QIcon(":/images/supprimer.png"));
        ui->message100->setIcon(QIcon(":/images/supprimer.png"));
        ui->message1000->setIcon(QIcon(":/images/supprimer.png"));
        ui->messagemaxint->setIcon(QIcon(":/images/supprimer.png"));
        ui->userdifferent10->setIcon(QIcon(":/images/supprimer.png"));
        ui->userdifferent30->setIcon(QIcon(":/images/supprimer.png"));
        ui->userdifferent100->setIcon(QIcon(":/images/supprimer.png"));
        ui->server20->setIcon(QIcon(":/image/supprimer.png"));
    }if(settings->value("succes/nbmessage").toInt()<0&&settings->value("succes/succes").toBool()==false){
        ui->message10->setToolTip("Impossible de l'obtenir, vous avez désactivé les succès.");
        ui->message100->setToolTip("Impossible de l'obtenir, vous avez désactivé les succès.");
        ui->message1000->setToolTip("Impossible de l'obtenir, vous avez désactivé les succès.");
        ui->messagemaxint->setToolTip("Impossible de l'obtenir, vous avez désactivé les succès.");
        ui->userdifferent10->setToolTip("Impossible de l'obtenir, vous avez désactivé les succès.");
        ui->userdifferent30->setToolTip("Impossible de l'obtenir, vous avez désactivé les succès.");
        ui->userdifferent100->setToolTip("Impossible de l'obtenir, vous avez désactivé les succès.");
        ui->server20->setToolTip("Impossible de l'obtenir, vous avez désactivé les succès.");
        ui->message10->setText("");
        ui->message100->setText("");
        ui->message1000->setText("");
        ui->messagemaxint->setText("");
        ui->userdifferent10->setText("");
        ui->userdifferent30->setText("");
        ui->userdifferent100->setText("");
        ui->server20->setText("");
        ui->message10->setIcon(QIcon(":/images/supprimer.png"));
        ui->message100->setIcon(QIcon(":/images/supprimer.png"));
        ui->message1000->setIcon(QIcon(":/images/supprimer.png"));
        ui->messagemaxint->setIcon(QIcon(":/images/supprimer.png"));
        ui->userdifferent10->setIcon(QIcon(":/images/supprimer.png"));
        ui->userdifferent30->setIcon(QIcon(":/images/supprimer.png"));
        ui->userdifferent100->setIcon(QIcon(":/images/supprimer.png"));
        ui->server20->setIcon(QIcon(":/images/supprimer.png"));
    }if(settings->value("succes/nbmessage").toInt()>=10){
        ui->message10->setToolTip("obtenus");
        ui->message10->setText("");
        ui->message10->setIcon(QIcon(":/images/Check_green.png"));
    }if(settings->value("succes/nbmessage").toInt()>=100){
        ui->message100->setToolTip("obtenus");
        ui->message100->setText("");
        ui->message100->setIcon(QIcon(":/images/Check_green.png"));
    } if(settings->value("succes/nbmessage").toInt()>=1000){
        ui->message1000->setToolTip("obtenus");
        ui->message1000->setText("");
        ui->message1000->setIcon(QIcon(":/images/Check_green.png"));
    } if(settings->value("succes/nbmessage").toInt()>=2147483647){
        ui->messagemaxint->setToolTip("obtenus");
        ui->messagemaxint->setText("");
        ui->messagemaxint->setIcon(QIcon(":/images/Check_green.png"));
    }if(settings->value("succes/10userSimultaneously").toBool()){
        ui->userdifferent10->setToolTip("obtenus");
        ui->userdifferent10->setText("");
        ui->userdifferent10->setIcon(QIcon(":/images/Check_green.png"));
    }if(settings->value("succes/30userSimultaneously").toBool()){
        ui->userdifferent30->setToolTip("obtenus");
        ui->userdifferent30->setText("");
        ui->userdifferent30->setIcon(QIcon(":/images/Check_green.png"));
    }if(settings->value("succes/100userSimultaneously").toBool()){
        ui->userdifferent100->setToolTip("obtenus");
        ui->userdifferent100->setText("");
        ui->userdifferent100->setIcon(QIcon(":/images/Check_green.png"));
    }if(settings->value("succes/20server").toBool()){
        ui->server20->setToolTip("obtenus");
        ui->server20->setText("");
        ui->server20->setIcon(QIcon(":/images/Check_green.png"));
    }

}
sucees::~sucees()
{
    delete ui;
}
void sucees::on_message10_clicked()
{
    if(settings->value("succes/nbmessage").toInt()<=10&&settings->value("succes/nbmessage").toInt()>=0&&settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour obtenir ce succès, il faut avoir envoyé 10 messages."));
    }else if(settings->value("succes/nbmessage").toInt()>=10){
        QMessageBox::information(this,tr("Info"),tr("Vous avez obtenu ce succès."));
    }else if(!settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour obtenir ce succès, il faut avoir envoyé 10 messages, mais vous avez desactivé les succès."));
    }
}
void sucees::on_message100_clicked()
{
    if(settings->value("succes/nbmessage").toInt()<=100&&settings->value("succes/nbmessage").toInt()>=0&&settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("info"),tr("Pour obtenir ce succès, il faut avoir envoyé 100 messages."));
    }else if(settings->value("succes/nbmessage").toInt()>=100){
        QMessageBox::information(this,tr("info"),tr("Vous avez obtenu ce succès."));
    }else if(!settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("info"),tr("Pour obtenir ce succès, il faut avoir envoyé 100 messages, mais vous avez desactivé les succès."));
    }
}
void sucees::on_message1000_clicked()
{
    if(settings->value("succes/nbmessage").toInt()<=1000&&settings->value("succes/nbmessage").toInt()>=0&&settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("info"),tr("Pour obtenir ce succès, il faut avoir envoyé 1000 messages."));
    }else if(settings->value("succes/nbmessage").toInt()>=1000){
        QMessageBox::information(this,tr("info"),tr("Vous avez obtenu ce succès."));
    }else if(!settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("info"),tr("Pour obtenir ce succès, il faut avoir envoyé 1000 messages, mais vous avez désactivé les succès."));
    }
}
void sucees::on_messagemaxint_clicked()
{
    if(settings->value("succes/nbmessage").toInt()<=2147483647 &&settings->value("succes/nbmessage").toInt()>=0&&settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("info"),tr("Pour obtenir ce succès, il faut avoir envoyé 2 147 483 647 messages."));
    }else if(settings->value("succes/nbmessage").toInt()>=2147483647){
        QMessageBox::information(this,tr("info"),tr("Vous avez obtenu ce succès."));
    }else if(!settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("info"),tr("Pour obtenir ce succès, il faut avoir envoyé 2 147 483 647 messages, mais vous avez désactiver les succès."));
    }
}
void sucees::on_saveNbMessage_toggled(bool checked)
{
    settings->setValue("succes/succes",checked);
}
void sucees::on_pushButton_2_clicked()
{
    settings->setValue("succes/nbmessage",0);
    int reponse = QMessageBox::question(this, tr("confirmation"), tr("le nombre de vos message va etre supimer et uniquemment le nombre atention cette option ne suprimeras pas vos message ecrit. voulez vous continuer ?"), QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QMessageBox::critical(this,tr("Supression prise en compte"),tr("La suppression de message(s) a bien été effectué. Vous avez actuellement 0 message enregistré."));
            ui->nbmessage->setText("Nombre de messages envoyés:"+QString::number(settings->value("succes/nbmessage").toInt()));
    }
}
void sucees::on_userdifferent10_clicked()
{
    if(!settings->value("succes/10userSimultaneously").toBool()&&settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour obtenu ce succès, il faut être connecté en même temps que 10 autres utilisateurs sur le même serveur."));
    }else if(settings->value("succes/10userSimultaneously").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Vous avez obtenu ce succès."));
    }else if(!settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour avoir ce succès, il faut être connecté en même temps que 10 autres utilisateurs sur le même serveur, mais vous avez désactiver les succès."));
    }}

void sucees::on_userdifferent30_clicked()
{
    if(!settings->value("succes/30userSimultaneously").toBool()&&settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour obtenir ce succès, il faut être connecté en même temps que 30 autres utilisateurs sur le même serveur."));
    }else if(settings->value("succes/30userSimultaneously").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Vous avez obtenu ce succès."));
    }else if(!settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour obtenir ce succès, il faut être connecté en même temps que 30 autres utilisateurs sur le même serveur, mais vous avez désactivé les succès."));
    }
}
void sucees::on_userdifferent100_clicked()
{
    if(!settings->value("succes/100userSimultaneously").toBool()&&settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour obtenir ce succès, il faut être connecté en même temps que 100 autres utilisateurs sur le même serveur."));
    }else if(settings->value("succes/100userSimultaneously").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Vous avez obtenu ce succès."));
    }else if(!settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour obtenir ce succès, il faut être connecté en même temps que 100 autres utilisateurs sur le même serveur, mais vous avez désactivé les succès."));
    }
}
void sucees::on_server20_clicked()
{
    if(!settings->value("succes/20server").toBool()&&settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour obtenir ce succès, il faut s'être connecté à 20 serveurs différents."));
    }else if(settings->value("succes/20server").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Vous avez obtenu ce succès."));
    }else if(!settings->value("succes/succes").toBool()){
        QMessageBox::information(this,tr("Info"),tr("Pour obtenir ce succès, il faut s'être connecté à 20 serveurs différents, mais vous avez désactivé les succès."));
    }
}


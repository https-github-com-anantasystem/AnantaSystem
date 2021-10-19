#include "startserveur.h"
#include "ui_startserveur.h"

startserveur::startserveur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startserveur)
{
    ui->setupUi(this);
}

startserveur::~startserveur()
{
    delete ui;
}
void startserveur::on_wifi_clicked()
{
    if(!QDesktopServices::openUrl(QUrl("client.exe"))){
        QMessageBox::information(this,tr("erreur a louverture du lien"),tr("le lien ne veut pas souvrir le programe client.exe a du etre modifier ou suprimer reinstaler le tchat"));
    }
    qApp->quit();
}
/*void startserveur::starclient(){
    socket = new QTcpSocket; //serveur
    connect(socket, &QTcpSocket::readyRead, this ,&startserveur::datareceived);
    connect(socket, &QTcpSocket::connected,this,&startserveur::connected);
    connect(socket, &QTcpSocket::disconnected,this,&startserveur::desconnect);
    connect(socket, &QTcpSocket::errorOccurred, this, &startserveur::socketerror);
}
void startserveur::datareceived()
{
    QDataStream in(socket);
    while (1) {
        if (messagesize == 0)
        {
            if (socket->bytesAvailable() < (int)sizeof(quint16))
                 return;

            in >> messagesize;
        }

        if (socket->bytesAvailable() < messagesize)
            return;
        // Si on arrive jusqu'? cette ligne, on peut r?cup?rer le message entier
        QMap<QString,QString> messageRecu;
        in >> messageRecu;
        processthemessage(messageRecu);
        // On remet la taille du message ? 0 pour pouvoir recevoir de futurs messages
        messagesize = 0;
    }
}
void Widget::processthemessage(QMap<QString,QString> message)
{
    if(message["type"]=="cmd"){
        processcomand(message);
    }else if(message["type"]=="msg"){
        displayMessagelist(generatemesage(message));
    }else{
        QMessageBox::critical(this, tr("erreur"), tr("un packet a été recu mais l'indantificateur : ") + message["type"] + tr(" est inconu."));
    }

}
void Widget::processcomand(QMap<QString, QString> commend)
{
    if (commend["message"] == "psedo?"){
        sentcommende("psedo_", returnpsedo());
    }else if (commend["message"]=="vertion?"){
        sentcommende("version",version);
    }else if (commend["message"]=="pesdoAnonimousinvalid"){
        QMessageBox::critical(this, tr("erreur"), tr("il faut un autre psedo que anonimous ou rien pour se conecter"));
    }else if(commend["message"]=="psedoalreadyuse"){
        QMessageBox::critical(this, tr("erreur"), tr("un autre client porte deja ce psedo changer de psedo pour vous connecter"));
    }else if(commend["message"]=="pseudoresembling"){
        QMessageBox::critical(this, tr("erreur"), tr("un autre client porte deja un psedo resemblant changer de psedo pour vous connecter"));
    }else if (commend["message"]=="update_") {
        displayMessagelist(commend["arg"]);
    }else if (commend["message"]=="isconnected") {
        ui->clientlist->addItem(commend["arg"]);
    }else{
        QMessageBox::critical(this, tr("erreur"), tr("un packet de comande a été recu mais la comande est incomprise."));
    }
}*/

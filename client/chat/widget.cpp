#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
    parametres(this),
    ui(new Ui::Widget)
{
    parametre parametres(this);
    settings = new QSettings("ananta system","tchat",this);
    if(!settings->contains("succes/succes")){
        settings->setValue("succes/succes",true);
    }if(!settings->contains("succes/nbmessage")){
        settings->setValue("succes/nbmessage",0);
    }if(!settings->contains("settings/SaveMessage")){
        settings->setValue("settings/SaveMessage",true);
    }if(!settings->contains("settings/visualNotification")){
        settings->setValue("settings/visualNotification",true);
    }if(!settings->contains("settings/SoundNotification")){
        settings->setValue("settings/SoundNotification",true);
    }if(!settings->contains("settings/transparencyIsActived")){
        settings->setValue("settings/transparencyIsActived", false);
    }if(!settings->contains("settings/color")){
        settings->setValue("settings/color","white");
    }if(!settings->contains("settings/path")){
        settings->setValue("settings/path",":/sound/notifdefault.wav");
    }if(!settings->contains("settings/transparency")){
        settings->setValue("settings/transparency","0.5");
    }if(!settings->contains("succes/10userSimultaneously")){
        settings->setValue("succes/10userSimultaneously", false);
    }if(!settings->contains("succes/30userSimultaneously")){
        settings->setValue("succes/30userSimultaneously", false);
    }if(!settings->contains("succes/100userSimultaneously")){
        settings->setValue("succes/100userSimultaneously", false);
    }if(!settings->contains("succes/server/nbserveur")){
        settings->setValue("succes/server/nbserveur", 0);
    }if(!settings->contains("succes/server/nbserveur")){
        settings->setValue("succes/server/nbserveur", 0);
    }
    ui->setupUi(this);
   version = "5.1";
   NbOfMessage = 0;
   nbuser=0;
   startTrayIcon();

   QString name = qgetenv("USER");
   if (name.isEmpty())
       name = qgetenv("USERNAME");
   ui->pseudo->setText(name);

   socket = new QTcpSocket; //serveur
   connect(socket, &QTcpSocket::readyRead, this ,&Widget::client_datareceived);
   connect(socket, &QTcpSocket::connected,this,&Widget::client_connected);
   connect(socket, &QTcpSocket::disconnected,this,&Widget::client_desconnect);
   connect(socket, &QTcpSocket::errorOccurred, this, &Widget::client_socketerror);///////////////////////////
   messagesize = 0;
   //conexion
   client_connectto("127.0.0.1", ui->serveurport->value());
   //selection de la couleur du theme
}

Widget::~Widget()
{
    delete ui;
    delete sticon;
}
void Widget::startTrayIcon(){
    sticon = new QSystemTrayIcon(this); // on construit notre icône de notification
    // Création du menu contextuel de notre icône
    QMenu* stmenu = new QMenu(this);
    QAction* actTexte1 = new QAction(tr("quiter"),this);
    QAction* condense = new QAction(tr("condenser la fenetre"), this);
    connect(qApp, &QGuiApplication::applicationStateChanged, this,  &Widget::changetransparency);
    stmenu->addAction(actTexte1);
    stmenu->addAction(condense);
    condense->setCheckable(true);
    sticon->setContextMenu(stmenu); // On assigne le menu contextuel à l'icône de notification
    QIcon icon(":/image/Ananta.png");
    sticon->setIcon(icon); // On assigne une image à notre icône
    sticon->show(); // On affiche l'icône
    connect(actTexte1, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(condense, SIGNAL(triggered()), this, SLOT(condesed()));
}
void Widget::on_parametrebuton_2_clicked()
{
    parametres.show();
}
void Widget::changetransparency(Qt::ApplicationState state){
    if(settings->value("transparencyIsActived").toDouble()){
        return;
    }
    if(state == Qt::ApplicationInactive){
        if(condenser){
           this->setWindowOpacity(settings->value("transparency").toDouble());
        }
    }else if(state == Qt::ApplicationActive){
        this->setWindowOpacity(1);
    }

}
void Widget::condesed(){
    if (socket->state()){
        if (condenser == false)
        {
            //ui->label->setVisible(false);
            ui->serveurip->setVisible(false);
            ui->psedo->setVisible(false);
            ui->label_4->setVisible(false);
            ui->serveurport->setVisible(false);
            ui->parametrebuton_2->setVisible(false);
            ui->clientlist->setVisible(false);
            this->setWindowFlags(Qt::WindowStaysOnTopHint);
            this->show();
            condenser = true;
            resize(610,89);
        }else if (condenser == true){
            //ui->label->setVisible(true);
            ui->serveurip->setVisible(true);
            ui->psedo->setVisible(true);
            ui->label_4->setVisible(true);
            ui->serveurport->setVisible(true);
            ui->parametrebuton_2->setVisible(true);
            ui->clientlist->setVisible(true);
            this->setWindowFlags(Qt::Window);
            condenser = false;
            this->show();
        }else{
            QMessageBox::critical(this,tr("bool condesed"),tr("erreur un bool ne pet pas avoir tois etat signalez le dans: parametre  puis discord"));
        }
    }else{
        QMessageBox::information(this,tr("passage en mode condensée"),tr("vous ne pouvez passer l'app en mode condensée que une fois connecter"));

    }
}
void helpcondesed(){
     QMessageBox::information(nullptr,QObject::tr("passage en mode condensée"),QObject::tr("vous ne pouvez passer l'app en mode condensée que une fois connecter"));
}
void Widget::client_displayMessagelist(QString message)
{
    if(settings->value("settings/SoundNotification").toBool())
    {
        QSound::play(settings->value("settings/path").toString());
    }
    if(settings->value("settings/visualNotification").toBool())
    {
        if(!QApplication::activeWindow()){
            auto text = QTextDocumentFragment::fromHtml(message);
            qDebug()  << tr("message:") << text.toPlainText();
            sticon->showMessage("",text.toPlainText(),QSystemTrayIcon::Information,2000);
        }
        QApplication::alert(this);
    }
    ui->messagelist->append(message);
}
void Widget::client_changestateconnectbuton(bool state)
{
    ui->conectbuton->setEnabled(state);
}
QString Widget::client_returnpsedo()
{
    return ui->psedo->text();
}
void Widget::on_conectbuton_clicked()
{
    if(ui->psedo->text()==""||ui->psedo->text()==" "||ui->psedo->text()=="anonymous"){
        QMessageBox::critical(this,tr("psedo invalid"),tr("vous ne pouvez avoir anonymous ou aucun psedo"));
        return;
    }
    client_connectto(ui->serveurip->text(), ui->serveurport->value());
    ui->clientlist->clear();
    client_displayconnectlabel(tr("<font color=\"#ff0000\">Déconnecté</font>"));
}
void Widget::client_displayconnectlabel(QString text)
{
    ui->conectstatelabel->setText(text);
}
void Widget::on_sentbuton_clicked()
{
    QString message = ui->mesage->text(); // si le if prend trop de temps l'utilisateur ne pouras pas modifier son message
    QString msg = message;
    if(message==""){
        QMessageBox::information(this,tr("erreur pasive | securitée anti DDOS"),tr("vous ne pouvez pas envoyer un message vide"));
        return;
    }
    if(settings->value("succes/succes").toBool()==true){
        settings->setValue("succes/nbmessage",settings->value("succes/nbmessage").toInt()+1);
    }
    //supression des widgetule de politesse des point et des majuscule
    message = message.toLower();
    if (message.contains(tr("stp","diminutif de s'il te plait")))
        message = message.remove(tr("stp","diminutif de s'il te plait"));
    if (message.contains(tr("s'il te plait")))
        message = message.remove(tr("s'il te plait"));
    if (message.contains("?"))
        message = message.remove("?");
    if (message.contains("."))
        message = message.remove(".");
    if (message.contains("!"))
        message = message.remove("!");
    if (message.contains("@"))
    message = message.remove("@");
    if(message.startsWith("/")){
        message = message.remove("/");
        client_processechatbot(message);
    }else if(message.startsWith(tr("chat bot"))){
        message.remove(tr("chat bot"));
        client_processechatbot(message);
    }else if(message.startsWith(tr("ananta systeme"))){
        message.remove(tr("ananta systeme"));
        client_processechatbot(message);
    }else if(message.startsWith(tr("ananta système"))){
        message.remove(tr("ananta système"));
       client_processechatbot(message);
    }else{
        client_sentdatamap("msg",msg);
    }
    ui->mesage->clear();
}
void Widget::client_processechatbot(QString command)
{
    srand (time(NULL));
   //reponse pré faite
   if (command==tr("bonjour")||command==tr("salut")||command==tr("hello")){//posibilier de question
       int random = rand() % 5 + 1;//on fait l'aleatoire
       if(random == 1){
           ui->messagelist->append(client_generatemesage(tr("bonjour") + ui->psedo->text()+".",tr("chat bot")));
       }else if(random == 2){
           ui->messagelist->append(client_generatemesage(tr("salut") + ui->psedo->text()+".",tr("chat bot")));
       }else if(random == 3){
           ui->messagelist->append(client_generatemesage(tr("salut") + ui->psedo->text()+".",tr("chat bot")));
       }else if(random == 4){
           ui->messagelist->append(client_generatemesage(tr("hello") + ui->psedo->text()+".",tr("chat bot")));
       }else if(random == 5){
           ui->messagelist->append(client_generatemesage(tr("hello👋") + ui->psedo->text()+".",tr("chat bot")));
       }
   }else if (command==tr("comment t'apelle tu")||command==tr("quel est ton nom")){
       int random = rand() % 2 + 1;
       if(random == 1){
           ui->messagelist->append(client_generatemesage(tr("tu peut mapeller ANANTA SYSTÈME."),tr("chat bot")));
       }else if(random == 2){
           ui->messagelist->append(client_generatemesage(tr("tu peut mapeller chat bot."),tr("chat bot")));
       }
   }else if (command==tr("qui est tu")){
       ui->messagelist->append(client_generatemesage(tr("je suis le chat bot crée par ananta systeme je suis encors tres inachever."),tr("chat bot")));
   }else if (command=="clear"){
       ui->messagelist->clear();
   }else if (command=="actualise"||command=="update"){
        client_sentcommende("updating");
   }else if (command==tr("merci")){
       int random = rand() % 7 + 1;
       if(random == 1){
           ui->messagelist->append(client_generatemesage(tr("de rien 😀"),tr("chat bot")));
       }else if(random == 2){
           ui->messagelist->append(client_generatemesage(tr("tout le plaisire et pour moi 😀"),tr("chat bot")));
       }else if(random == 3){
           ui->messagelist->append(client_generatemesage(tr("tout le plaisire et pour moi!"),tr("chat bot")));
       }else if(random == 3){
           ui->messagelist->append(client_generatemesage(tr("de rien !"),tr("chat bot")));
       }else if(random == 4){
           ui->messagelist->append(client_generatemesage(tr("mais je suis la pour ca bien sur 😀"),tr("chat bot")));
       }else if(random == 5){
           ui->messagelist->append(client_generatemesage(tr("mais je suis la pour ca bien sur !"),tr("chat bot")));
       }else if (random == 6){
            ui->messagelist->append(client_generatemesage(tr("quand tu ne me parle pas je fait que des acion repetitive... recevoir des message te les aficher😥"),tr("chat bot")));
       }else if (random == 7){
            ui->messagelist->append(client_generatemesage(tr("quand tu ne me parle pas je m'enuie 😥"),tr("chat bot")));
   }else if (command==tr("condenses")||command==tr("condense")||command==tr("condense menu")){
       condesed();
    }else if (command==tr("comment condenser la fenetre")||command==tr("comment condenser le menu")||command==tr("compacter la fenetre")){
       int random = rand() % 3 + 1;
       if(random == 1){
           client_displayMessagelist(client_generatemesage(tr("il sufit de taper la commende /condense", "atension a metre la meme sytax que la ligne de juste au dessu"),tr("chat bot")));
       }else if(random == 2){
           ui->messagelist->append(client_generatemesage(tr("tu peut allez dans parametre et cliquer sur passer en mode condensé"),tr("chat bot")));
       }else if(random == 3){
           ui->messagelist->append(client_generatemesage(tr("il te sufit de faire clique droit sur l'icone dans la bare des tache et cliquer sur passer en mode condensé"),tr("chat bot")));
       }
   }
   }else{
      client_displayMessagelist(client_generatemesage(tr("desolée je n'ai pas compris"),tr("chat bot")));
  }
}
//serveur
void Widget::client_connectto(QString ip, int port)
{
    client_displayMessagelist(client_generatemesage(tr("tentative de connexion en cour"),tr("chat bot")));
    client_changestateconnectbuton(false);
    socket->abort();
    socket->connectToHost(ip, port);
    client_displayconnectlabel(tr("<font color=\"#894B23\">tenetative lancé</font>"));
}
void Widget::client_connected()
{
    QString textmessage = client_generatemesage(tr("conexion reusi"), tr("chat bot"));
    client_sentdatamap("connection");
    client_displayMessagelist(textmessage);
    client_changestateconnectbuton(true);
    client_displayconnectlabel(tr("<font color=\"#70AD47\">connecté</font>"));
    for (int compteur {settings->value("succes/server/nbserveur").toInt()}; compteur > 0; --compteur)
    {
        if(socket->peerAddress().Any==settings->value("succes/server/"+QString::number(settings->value("succes/server/nbserveur").toInt()))){
            return;
        }
    }
    settings->setValue("succes/server/"+QString::number(settings->value("succes/server/nbserveur").toInt()),socket->peerAddress().Any);
    settings->setValue("succes/server/nbserveur", settings->value("succes/server/nbserveur").toInt()+1);
    if(settings->value("succes/server/nbserveur").toInt()==20){
        settings->setValue("succes/20server", true);
    }
}
void Widget::client_desconnect()
{
    QString textmessage = client_generatemesage(tr("déconecter du serveur"),tr("chat bot"));
    client_displayconnectlabel(tr("<font color=\"#ff0000\">Déconnecté</font>"));
    client_displayMessagelist(textmessage);
    client_changestateconnectbuton(true);
}
void Widget::client_socketerror(QAbstractSocket::SocketError erreur)
{
    client_displayconnectlabel(tr("<font color=\"#ff0000\">Déconnecté</font>"));
    switch(erreur) // On affiche un message diff?rent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            client_displayMessagelist(client_generatemesage(QObject::tr("ERREUR : le serveur primaire n'a pas pu étre trouvé. Vérifiez le nom du serveur et le mot de passe."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::ConnectionRefusedError:
            client_displayMessagelist(client_generatemesage(QObject::tr("ERREUR : le serveur primaire a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP et le port."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::RemoteHostClosedError:
            client_displayMessagelist(client_generatemesage(QObject::tr("ERREUR : le serveur primaire a coupé la connexion."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::SocketAccessError:
            client_displayMessagelist(client_generatemesage(QObject::tr("L'opération a échoué car l'application ne dispose pas des privilèges requis."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;
        case QAbstractSocket::SocketResourceError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Le système local a manqué de ressources (par exemple, trop de sockets)."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::SocketTimeoutError:
            client_displayMessagelist(client_generatemesage(QObject::tr("loperation a expirée"),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::DatagramTooLargeError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Le datagramme était plus grand que la limite du système d'exploitation (qui peut être aussi basse que 8192 octets)"),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;
        case QAbstractSocket::NetworkError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Une erreur s'est produite avec le réseau (par exemple, le câble réseau a été \"accidentellement\" débranché)."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::UnsupportedSocketOperationError:
            client_displayMessagelist(client_generatemesage(QObject::tr("L'opération de socket demandée n'est pas prise en charge par le système d'exploitation local (par exemple, absence de prise en charge d'IPv6)."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyAuthenticationRequiredError:
            client_displayMessagelist(client_generatemesage(QObject::tr(" le proxy requiert une authentification."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyConnectionRefusedError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Impossible de contacter le serveur proxy car la connexion à ce serveur a été refusée"),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyConnectionClosedError:
            client_displayMessagelist(client_generatemesage(QObject::tr("La connexion au serveur proxy a été fermée de manière inattendue (avant que la connexion au pair final ne soit établie)"),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyConnectionTimeoutError:
            client_displayMessagelist(client_generatemesage(QObject::tr("La connexion au serveur proxy a expiré ou le serveur proxy a cessé de répondre lors de la phase d'authentification."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyNotFoundError:
            client_displayMessagelist(client_generatemesage(QObject::tr("le proxi est inrouvable"),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyProtocolError:
            client_displayMessagelist(client_generatemesage(QObject::tr("La négociation de connexion avec le serveur proxy a échoué, car la réponse du serveur proxy n'a pas pu être comprise."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::OperationError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Une opération a été tentée alors que le socket était dans un état qui ne l'autorisait pas."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::TemporaryError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Une erreur temporaire s'est produite (par exemple, l'opération bloquerait et le socket n'est pas bloquant)."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

        case QAbstractSocket::UnknownSocketError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Une erreur non identifiée s'est produite."),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;

    default:
            client_displayMessagelist(client_generatemesage(QObject::tr("ERREUR : ") + socket->errorString(),tr("chat bot")));
            client_changestateconnectbuton(true);
        break;
    }
}
// optionelle
void Widget::client_sentdatamap(const QMap<QString,QString> sendmap)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << sendmap;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    socket->write(paquet); // On envoie le paquet
}
void Widget::client_sentdatamap(const QString type){
    QMap<QString,QString> sendmap;
    sendmap["type"]=type;
    sendmap["psedo"]=client_returnpsedo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    client_sentdatamap(sendmap);

}
void Widget::client_sentdatamap(const QString type, QString message, QString psedo, QDateTime seconde, QDateTime minute, QDateTime heurs, QDateTime NoJour, QDate jour){
    QMap<QString,QString> sendmap;
    sendmap["type"]=type;
    sendmap["message"]=message;
    sendmap["psedo"]=psedo;
    sendmap["secondofsending"]=seconde.toString();
    sendmap["minuteofsending"]=minute.toString();
    sendmap["sendingtime"]=heurs.toString();
    sendmap["sendingdate"]=NoJour.toString();
    sendmap["shippingday"]=jour.toString();
    client_sentdatamap(sendmap);
}
void Widget::client_sentdatamap(const QString type, QString message, QString psedo){
    QMap<QString,QString> sendmap;
    sendmap["type"]=type;
    sendmap["message"]=message;
    sendmap["psedo"]=psedo;
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    client_sentdatamap(sendmap);
}
void Widget::client_sentdatamap(const QString type, QString message){
    QMap<QString,QString> sendmap;
    sendmap["type"]=type;
    sendmap["message"]=message;
    sendmap["psedo"]=client_returnpsedo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    client_sentdatamap(sendmap);
}
void Widget::client_sentcommende(const QString commende){
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=commende;
    sendmap["psedo"]=client_returnpsedo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    client_sentdatamap(sendmap);
}
void Widget::client_sentcommende(const QString commende, QString arg){
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=commende;
    sendmap["arg"]=arg;
    sendmap["psedo"]=client_returnpsedo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("m");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("ddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");;
    client_sentdatamap(sendmap);
}
void Widget::client_datareceived()
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
        client_processthemessage(messageRecu);
        // On remet la taille du message ? 0 pour pouvoir recevoir de futurs messages
        messagesize = 0;
    }
}
void Widget::client_processthemessage(QMap<QString,QString> message)
{
    if(message["type"]=="cmd"){
        client_processcomand(message);
    }else if(message["type"]=="msg"){
        client_displayMessagelist(client_generatemesage(message));
    }else if(message["type"]=="connection"){
        ui->clientlist->addItem(message["psedo"]);
        ++nbuser;
        if(nbuser==10){
            settings->setValue("succes/10userSimultaneously", true);
        }else if(nbuser==30){
            settings->setValue("succes/30userSimultaneously", true);
        }else if(nbuser==100){
            settings->setValue("succes/100userSimultaneously", true);
        }
    }else{
        QMessageBox::critical(this, tr("erreur"), tr("un packet a été recu mais l'indantificateur : ") + message["type"] + tr(" est inconu."));
    }

}
void Widget::client_processcomand(QMap<QString, QString> commend)
{
    if (commend["message"] == "psedo?"){
        client_sentcommende("psedo_", client_returnpsedo());
    }else if (commend["message"]=="vertion?"){
        client_sentcommende("version",version);
    }else if (commend["message"]=="pesdoAnonimousinvalid"){
        QMessageBox::critical(this, tr("erreur"), tr("il faut un autre psedo que anonimous ou rien pour se conecter"));
    }else if(commend["message"]=="psedoalreadyuse"){
        QMessageBox::critical(this, tr("erreur"), tr("un autre client porte deja ce psedo changer de psedo pour vous connecter"));
    }else if(commend["message"]=="pseudoresembling"){
        QMessageBox::critical(this, tr("erreur"), tr("un autre client porte deja un psedo resemblant changer de psedo pour vous connecter"));
    }else if (commend["message"]=="update_") {
        client_displayMessagelist(commend["arg"]);
    }else if (commend["message"]=="isconnected"){
        ui->clientlist->addItem(commend["arg"]);
        ++nbuser;
    }else if(commend["message"]=="desconnected"){
        if(ui->clientlist->findItems(commend["arg"],Qt::MatchCaseSensitive).size()==1){
            ui->clientlist->removeItemWidget(ui->clientlist->findItems(commend["arg"],Qt::MatchCaseSensitive)[1]); //on suprime le nom specifier
            QMessageBox::critical(this, tr("supression de client"), tr("le client vien d'etre suprimer"));
        }else{
            for (int compteur {ui->clientlist->findItems(commend["arg"],Qt::MatchCaseSensitive).size()-1}; compteur > 0; --compteur) //tan que des utilistateur porte le nom specifier
            {
                ui->clientlist->removeItemWidget(ui->clientlist->findItems(commend["arg"],Qt::MatchCaseSensitive)[1]); //on suprime le nom specifier
                QMessageBox::critical(this, tr("supression de client"), tr("le client vien d'etre suprimer"));
                --nbuser;
            }
        }
    }else{
        QMessageBox::critical(this, tr("erreur"), tr("un packet de comande a été recu mais la comande est incomprise."));
    }
}
QString Widget::client_generatedate()
{
    QString heurs = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString Date = QDateTime::currentDateTime().toString(" dd MM yyyy");
    QDateTime::fromString(heurs, "hh:mm:ss");
    return(tr("<span style=\"font-size: 10px\"> Le ")+Date+tr("</span> <span style=\"font-size: 10px\">à ")+heurs+tr(" </span><br/>"));

}
QString Widget::client_generatedate(QMap<QString, QString> date)
{
    return(tr("<span style=\"font-size: 10px\"> Le ")+date["shippingday"]+" "+date["sendingdate"]+"/"+date["shippingmonth"]+"/"+date["shippingyears"] +tr("</span> <span style=\"font-size: 10px\"> à ")+date["sendingtime"]+":"+date["minuteofsending"]+tr(" </span><br/>"));

}
QString Widget::client_generatemesage(QString message, QString psedo)
{
    if(psedo == "" ||psedo == " "){
        psedo = "anonymous";
    }
    return(tr("<span style=\"font-size: 12px; font-weight: bold;\">")+psedo+tr("</span>")+client_generatedate()+tr("<span style=\"font-size: 14px; \">")+message+tr("</span><br/><br/>"));
}
QString Widget::client_generatemesage(QMap<QString, QString> message){
    if(message["psedo"] == "" ||message["psedo"] == " "){
        message["psedo"] = "anonymous";
    }
    return(tr("<span style=\"font-size: 12px; font-weight: bold;\">")+message["psedo"]+tr("</span>")+client_generatedate(message)+tr("<span style=\"font-size: 14px; \">")+message["message"]+tr("</span><br/><br/>"));
}

void Widget::on_psedo_editingFinished()
{
   client_sentcommende("change_psedo",ui->psedo->text());
}


#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
    parametres(saveMessage,this),
    ui(new Ui::Widget)
{
    parametre parametres(saveMessage,this);
    settings = new QSettings("Ananta System","Tchat 5.0",this);
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
    }if(!settings->contains("succes/10server")){
        settings->setValue("succes/20server", false);
    }
    ui->setupUi(this);
    startserveur();// j'ai peur que le serveur se démmare trop tard
   version = "5.0";
   server_recoverallfile();
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
   connect(socket, &QTcpSocket::disconnected,this,&Widget::client_disconnect);
   connect(socket, &QTcpSocket::errorOccurred, this, &Widget::client_socketerror);
   messagesize = 0;
   //Connexion
   client_connectto("127.0.0.1", ui->serveurport->value());
   //Sélection de la couleur du theme
   qApp->setPalette(parametres.starttheme());
}

Widget::~Widget()
{
    delete ui;
    delete sticon;
}
void Widget::startTrayIcon(){
    sticon = new QSystemTrayIcon(this); // On construit notre icône de notification
    // Création du menu contextuel de notre icône
    QMenu* stmenu = new QMenu(this);
    QAction* actTexte1 = new QAction(tr("Quitter"),this);
    QAction* condense = new QAction(tr("Condenser la fenêtre"), this);
    connect(qApp, &QGuiApplication::applicationStateChanged, this,  &Widget::changetransparency);
    stmenu->addAction(actTexte1);
    stmenu->addAction(condense);
    condense->setCheckable(true);
    sticon->setContextMenu(stmenu); // On assigne le menu contextuel à l'icône de notification
    QIcon icon(":/images/Ananta.png");
    sticon->setIcon(icon); // On assigne une image à notre icône
    sticon->show(); // On affiche l'icône
    connect(actTexte1, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(condense, SIGNAL(triggered()), this, SLOT(condesed()));
}
void Widget::startserveur()
{
    m_serveur = new QTcpServer(this);
    if (!m_serveur->listen(QHostAddress::Any, 2048)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 2048
    {
        // Si le serveur n'a pas été démarré correctement
        if (!m_serveur->listen(QHostAddress::Any)) // Démarrage du serveur sur toutes les IP disponibles
        {
            // Si le serveur n'a pas été démarré correctement
            server_displayMessagelist(server_generatemesage(tr("Le serveur n'a pas pu être démarré. Raison :<br />") + m_serveur->errorString(),tr("Serveur Bot")));
            close();
        }
    }
    else
    {
        // Si le serveur a été démarré correctement
        server_displayMessagelist(server_generatemesage(tr("Le serveur a été démarré sur le port <strong>") + QString::number(m_serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter."), tr("Chat Bot")));
        connect(m_serveur, &QTcpServer::newConnection, this, &Widget::server_newconect);
    }
    QString ip;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             ip = (address.toString());
    }
    qDebug() <<ip;
    ui->serveurip->setText(ip);
    ui->serveurport->setValue(m_serveur->serverPort());
}
void Widget::on_parametrebutton_clicked()
{
    parametres.show();
}
void Widget::changetransparency(Qt::ApplicationState state){
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
            ui->pseudo->setVisible(false);
            ui->label_4->setVisible(false);
            ui->serveurport->setVisible(false);
            ui->parametrebutton->setVisible(false);
            ui->clientlist->setVisible(false);
            this->setWindowFlags(Qt::WindowStaysOnTopHint);
            this->show();
            condenser = true;
            resize(610,89);
        }else if (condenser == true){
            //ui->label->setVisible(true);
            ui->serveurip->setVisible(true);
            ui->pseudo->setVisible(true);
            ui->label_4->setVisible(true);
            ui->serveurport->setVisible(true);
            ui->parametrebutton->setVisible(true);
            ui->clientlist->setVisible(true);
            this->setWindowFlags(Qt::Window);
            condenser = false;
            this->show();
        }else{
            QMessageBox::critical(this,tr("bool condesed"),tr("Erreur, un boolean est en défaut. Veuillez nous contacter sur notre Discord dans: Paramètres -> Discord"));
        }
    }else{
        QMessageBox::information(this,tr("passage en mode condensée"),tr("Vous ne pouvez passer l'app en mode condensé qu'une fois connecté."));

    }
}
void Widget::server_displayMessagelist(QString message)
{
    ui->messagelist->append(message);
}
//serveur
void Widget::server_sentmessagetoall(const QMap<QString, QString> &message)
{
    QByteArray pack;
    QDataStream out(&pack, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (pack.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message
    //Sending
    for(int i = 0; i < clientsList.size(); i++)
    {
        clientsList[i]->getSocket()->write(pack);
    }
}
void Widget::server_sentmessageto(const QMap<QString, QString> &message, int NoUtilisateur)
{
    QByteArray pack;
    QDataStream out(&pack, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (pack.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message
    //Sending
    clientsList[NoUtilisateur]->getSocket()->write(pack);
}
void Widget::server_sentmessagetoall(const QString type, QString message, QString pseudo){
    QMap<QString,QString> sendmap;
    sendmap["type"]=type;
    sendmap["message"]=message;
    sendmap["pseudo"]=pseudo;
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    server_sentmessagetoall(sendmap);
}
void Widget::server_sentmessageto(const QString &message, int NoUtilisateur)
{
    QMap<QString,QString> sendmap;
    sendmap["type"]="msg";
    sendmap["message"]=message;
    sendmap["pseudo"]="serveur"+client_returnpseudo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    server_sentmessageto(sendmap,NoUtilisateur);
}
void Widget::server_sentcomandto(const QString &message ,int usernaime)
{
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=message;
    sendmap["pseudo"]="serveur"+client_returnpseudo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    server_sentmessageto(sendmap,usernaime);

}
void Widget::server_sentcomandto(const QString &message,QString arg ,int usernaime)
{
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=message;
    sendmap["arg"]=arg;
    sendmap["pseudo"]="serveur"+client_returnpseudo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    server_sentmessageto(sendmap,usernaime);

}
void Widget::serveur_sentcommande(const QString commande, QString arg){
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=commande;
    sendmap["arg"]=arg;
    sendmap["pseudo"]="serveur"+client_returnpseudo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    server_sentmessagetoall(sendmap);
}
void Widget::server_newconect()
{
    utilisateur* newClient = new utilisateur(m_serveur->nextPendingConnection());
    clientsList.append(newClient);
    connect(clientsList.last()->getSocket(), SIGNAL(readyRead()), this, SLOT(server_datareceived()));
    connect(clientsList.last()->getSocket(), SIGNAL(disconnected()), this, SLOT(server_disconnectclients()));
    for(int i = 0; i < saveMessage.size()-1; i++)
    {
        server_sentmessageto(saveMessage[i],clientsList.size()-1);
    }
}
void Widget::server_connect(const QMap<QString, QString> &connectpack, int usernaime){
    clientsList[usernaime]->editpseudo(connectpack["pseudo"]);
    clientsList[usernaime]->editversion(connectpack["version"]);
    server_sentmessagetoall(connectpack);
}
void Widget::server_datareceived()
{
    int index = server_findIndex(qobject_cast<QTcpSocket*>(sender()));
      utilisateur* sendingClient = clientsList[index];
      QTcpSocket* socket = sendingClient->getSocket();

      if(socket == nullptr) {
        server_displayMessagelist(server_generatemesage(tr("erreur lors de la recherche du client qui a envoyé le paquet (non il y a pas de jeux de mot pouris)"),tr("serveur bot")));
        return; //Error
      }
      QDataStream in(socket);

        while(1) {
            if(sendingClient->getmessageSize() == 0) { //Try to catch
                if(socket->bytesAvailable() < static_cast<int>(sizeof(quint16))) {
                    return;
                }

                quint16 messageSize;
                in >> messageSize;
                sendingClient->setmessageSize(messageSize);
            }

            if(socket->bytesAvailable() < sendingClient->getmessageSize()) { //Part of the message missing
            return;
            }

            QMap<QString, QString>message;
            in >> message;
            sendingClient->setmessageSize(static_cast<quint16>(0));
        if(message["type"]=="cmd"){
            server_processcomand(message,index);
        }else if(message["type"]=="msg"){
            //if(sendingClient->getpseudo()==""||sendingClient->getpseudo()=="anonymous"||(sendingClient->getversion()!="4.1.0 beta 1" && sendingClient->getversion()!="4.1.0 beta 2")){
                /*if(sendingClient->getpseudo()=="anonymous"){
                    server_sentmessageto(server_generatemesage(tr("erreur vous ne pouvez pas envoyer de message au serveur pour le moment le serveur nautorise pas le pseudo: ")+sendingClient->getpseudo(),tr("serveur bot")),index);
                    server_sentcomandto("pseudo?",index);
                    return;
                }else if(sendingClient->getpseudo()==""){
                    server_sentmessageto(server_generatemesage(tr("erreur vous ne pouvez pas envoyer de message au serveur pour le moment le serveur nautorise pas les pseudo vide"),tr("serveur bot")),index);
                    server_sentcomandto("pseudo?",index);
                    return;
                }else if(sendingClient->getversion()!="4.1.0"){
                    server_sentmessageto(server_generatemesage(tr("erreur vous ne pouvez pas envoyer de message. le serveur a pas une version du tchat compatible avec la vautre"),tr("serveur bot")),index);
                    server_sentcomandto("version?",index);
                    return;
                }else{
                    server_sentmessageto(tr("erreur indefini sur lidantfication de ton satut info de debug : pseudo: ")+sendingClient->getpseudo()+tr(" version ")+sendingClient->getversion(),index);
                    return;
                }
            }else{*/
                server_sentmessagetoall(message);
                if(settings->value("settings/SaveMessage").toBool()){
                    server_writetofile(message);
                }
            }else if(message["type"]=="connection"){
                server_connect(message, index);
            }

        //}else{
            //QMessageBox::critical(this, tr("erreur"), tr("un paquet de comande a été recu mais la l'idantificateur ")+ message["type"] +tr("est incompri."));
            //server_displayMessagelist(server_generatemesage(tr("un paquet de comande a été recu mais la l'idantificateur ")+ message["type"] +tr("est incompri."),tr("serveur bot")));
        }
        sendingClient->setmessageSize(static_cast<quint16>(0));
    }
//}
void Widget::server_disconnectclients()
{
    QTcpSocket* disconnectingClientSocket = qobject_cast<QTcpSocket*>(sender());

    if(disconnectingClientSocket == nullptr) //Error
    {
        server_displayMessagelist(server_generatemesage(tr("Erreur fatal: les clients ne peuvent pas être supprimés. Tentative de suppression puis fermeture!"),tr("Serveur Bot")));
        QMessageBox::critical(this, tr("Erreur fatal"),tr("Les clients ne peuvent pas être supprimés. Nouvelle tentative de suppression puis fermeture!"));
        return;
    }

    int index = server_findIndex(disconnectingClientSocket);
    utilisateur* disconnectingClient = clientsList[index];
    serveur_sentcommande("disconnected",disconnectingClient->getpseudo());
    //server_sentmessagetoall("msg",disconnectingClient->getpseudo()+tr("</strong> vient de se déconnecter !"),tr("serveur bot"));

    clientsList.removeOne(disconnectingClient);
    delete disconnectingClient;
}
int Widget::server_findIndex(QTcpSocket* socket)
{
    int index = 0;

    while(clientsList[index]->getSocket() != socket)
    {
        index++;
    }

    return index;
}
void Widget::server_writetofile(QMap<QString, QString> FluxFile)
{
    saveMessage.push_back(FluxFile);
    ++NbOfMessage;
    QFile file("chat.dat");
    if (!file.open(QIODevice::WriteOnly)){
            server_displayMessagelist(server_generatemesage(tr("Il est impossible d'écrire dans le fichier."),tr("Tchat Bot")));
            return;
        }
    QDataStream out(&file);
    out <<saveMessage;
}
void Widget::server_recoverallfile()
{
    QFile fichier("chat.dat");

   if(fichier.open(QIODevice::ReadOnly))
   {
       QByteArray paquet;
       paquet = fichier.readAll();// Lecture entier de notre fichier en octet
       QDataStream out(paquet);
       out>>saveMessage;
   }
   else
   {
       server_displayMessagelist(server_generatemesage(tr("Le fichier est inaxcessible"), tr("System Tchat Bot")));

   }
}
void Widget::server_processcomand(QMap<QString, QString> command, int noclient)
{
    if (command["message"]=="pseudo"){
        if(command["arg"]=="anonymous"){
            server_sentcomandto("pseudoanonymousinvalid", noclient);
            return;
        }else{
            for(int i = 1; i < clientsList.size(); i++)
            {
                if(clientsList[i]->getpseudo()==command["pseudo"] && i != noclient){
                    server_sentcomandto("pseudoalreadyuse",noclient);
                    return;
                }else if(clientsList[i]->getpseudo().remove(" ")==command.remove(" ") && i != noclient){
                    server_sentcomandto("pseudoresembling",noclient);
                    return;
                }
            }
            clientsList[noclient]->editpseudo(command["arg"]);
            srand (time(NULL));
            int random = rand() % 4 + 1;
            if(random == 1){
                server_sentmessagetoall("msg",clientsList[noclient]->getpseudo() + tr(" est connecté."),tr("Tchat Bot"));
            }else if(random == 2){
                 server_sentmessagetoall("msg",clientsList[noclient]->getpseudo() + tr(" vient d'arriver dans le salon."),tr("Tchat Bot"));
            }else if(random == 3){
                server_sentmessagetoall("msg",clientsList[noclient]->getpseudo() + tr(" vient de nous rejoindre."),tr("Tchat Bot"));
            }else if(random == 4){
                server_sentmessagetoall("msg",tr("Il ne nous manquait plus que ")+clientsList[noclient]->getpseudo()+ tr(" heureusement il nous a rejoint."),tr("Tchat Bot"));
            }
            //serveur_sentcommande("isconnected", clientsList[noclient]->getpseudo());
            if(noclient==0){return;}
            for(int i = 1; i < clientsList.size(); i++)
            {
                if(i==noclient){i++;}
                if(i>clientsList.size()){return;}
                server_sentcomandto("isconnected", clientsList[i-1]->getpseudo(),noclient);
            }
        }
    }else if(command["message"]=="version"){
        clientsList[noclient]->editversion(command["arg"]);
    }else if (command["message"]=="change_psedo") {
        for(int i = 1; i < clientsList.size(); i++)
        {
            if(clientsList[i]->getpseudo()==command["arg"] && i != noclient){//si c'est le meme on coupe et on envoie une erreur
                server_sentcomandto("pseudoalreadyuse",noclient);
                return;
            }else if(clientsList[i]->getpseudo().remove(" ")==command["arg"].remove(" ") && i != noclient){//si c'est resembleaut on coupe et on envoie une erreur
                server_sentcomandto("pseudoresembling",noclient);
                return;
            }
        }
        server_sentmessagetoall("msg",clientsList[noclient]->getpseudo()+" a changer son psedo en "+ command["arg"],"Tchat Bot");
        clientsList[noclient]->editpseudo(command["arg"]);
    }else{
        QMessageBox::critical(this, tr("erreur"), tr("Un paquet de commande a été reçu mais la commande est incomprise."));
    }
}
QString Widget::server_generatedate()
{
    QString heures = QDateTime::currentDateTime().toString(" hh:mm:ss ");
    QString Date = QDateTime::currentDateTime().toString(" dd MM yyyy ");
    QDateTime::fromString(heures, " hh:mm:ss ");
    return(tr("<span style=\"font-size: 10px\"> Le ")+Date+tr("</span> <span style=\"font-size: 10px\">à ")+heures+tr(" </span><br/>"));
}
QString Widget::server_generatemesage(QString message, QString pseudo)
{
    return(tr("<span style=\"font-size: 12px; color:#000000; font-weight: bold;\">")+pseudo+tr("</span>")+server_generatedate()+tr("<span style=\"font-size: 14px; color:#2F2F2F\">")+message+tr("</span><br/><br/>"));
}

//client
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
            qDebug()  << tr("Message:") << text.toPlainText();
            sticon->showMessage("",text.toPlainText(),QSystemTrayIcon::Information,2000);
        }
        QApplication::alert(this);
    }
    ui->messagelist->append(message);
}
void Widget::client_changestateconnectbutton(bool state)
{
}
QString Widget::client_returnpseudo()
{
    return ui->pseudo->text();
}
void Widget::on_conectbutton_clicked()
{
    if(ui->pseudo->text()==""||ui->pseudo->text()==" "||ui->pseudo->text()=="anonymous"){
        QMessageBox::critical(this,tr("pseudo invalid"),tr("Vous devez posseder un pseudo (anonymous est interdit)."));
        return;
    }
    client_connectto(ui->serveurip->text(), ui->serveurport->value());
    ui->clientlist->clear();
    client_displayconnectlabel(tr("<font color=\"#ff0000\">Déconnecté</font>"));
}
void Widget::client_displayconnectlabel(QString text)
{
}
void Widget::on_sentbutton_clicked()
{
    QString message = ui->mesage->text(); // si le if prend trop de temps l'utilisateur ne pouras pas modifier son message
    QString msg = message;
    if(message==""){
        QMessageBox::information(this,tr("Erreur passive: Securitée anti-DDOS"),tr("Vous ne pouvez pas envoyer un message vide."));
        return;
    }
    if(settings->value("succes/succes").toBool()==true){
        settings->setValue("succes/nbmessage",settings->value("succes/nbmessage").toInt()+1);
    }
    //suppression des widgetule de politesse des point et des majuscule
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
    }else if(message.startsWith(tr("tchat bot"))){
        message.remove(tr("tchat bot"));
        client_processechatbot(message);
    }else if(message.startsWith(tr("ananta system"))){
        message.remove(tr("ananta system"));
        client_processechatbot(message);
    }else if(message.startsWith(tr("ananta system"))){
        message.remove(tr("ananta system"));
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
           ui->messagelist->append(client_generatemesage(tr("Bonjour") + ui->pseudo->text()+".",tr("Tchat Bot")));
       }else if(random == 2){
           ui->messagelist->append(client_generatemesage(tr("Salut") + ui->pseudo->text()+".",tr("Tchat Bot")));
       }else if(random == 3){
           ui->messagelist->append(client_generatemesage(tr("Salut🖖") + ui->pseudo->text()+".",tr("Tchat Bot")));
       }else if(random == 4){
           ui->messagelist->append(client_generatemesage(tr("Hello") + ui->pseudo->text()+".",tr("Tchat Bot")));
       }else if(random == 5){
           ui->messagelist->append(client_generatemesage(tr("Hello👋") + ui->pseudo->text()+".",tr("Tchat Bot")));
       }
   }else if (command==tr("comment t'apelle tu")||command==tr("quel est ton nom")){
       int random = rand() % 2 + 1;
       if(random == 1){
           ui->messagelist->append(client_generatemesage(tr("Tu peux m'appeller Tchat Bot."),tr("Tchat Bot")));
       }else if(random == 2){
           ui->messagelist->append(client_generatemesage(tr("Tu peux m'appeller Tchat Bot 😊."),tr("Tchat Bot")));
       }
   }else if (command==tr("qui est tu")){
       ui->messagelist->append(client_generatemesage(tr("Je suis le Tchat Bot crée par les développeurs de Ananta System, je suis encore très inachevé."),tr("Tchat Bot")));
   }else if (command=="clear"){
       ui->messagelist->clear();
   }else if (command=="actualise"||command=="update"){
        client_sentcommande("updating");
   }else if (command==tr("merci")){
       int random = rand() % 7 + 1;
       if(random == 1){
           ui->messagelist->append(client_generatemesage(tr("De rien 😀"),tr("Tchat Bot")));
       }else if(random == 2){
           ui->messagelist->append(client_generatemesage(tr("Tout le plaisir est pour moi 😀"),tr("Tchat Bot")));
       }else if(random == 3){
           ui->messagelist->append(client_generatemesage(tr("Tout le plaisir est pour moi!"),tr("Tchat Bot")));
       }else if(random == 3){
           ui->messagelist->append(client_generatemesage(tr("De rien !"),tr("Tchat Bot")));
       }else if(random == 4){
           ui->messagelist->append(client_generatemesage(tr("Mais je suis là pour ça bien sûr 😀"),tr("Tchat Bot")));
       }else if(random == 5){
           ui->messagelist->append(client_generatemesage(tr("Mais je suis là pour ça bien sûr !"),tr("Tchat Bot")));
       }else if (random == 6){
            ui->messagelist->append(client_generatemesage(tr("Quand tu ne me parle pas je fais que des actions répétitives, recevoir des messages et les afficher😥..."),tr("Tchat Bot")));
       }else if (random == 7){
            ui->messagelist->append(client_generatemesage(tr("Quand tu ne me parle pas je m'ennuie 😥"),tr("Tchat Bot")));
   }else if (command==tr("condenses")||command==tr("condense")||command==tr("condense menu")){
       condesed();
    }else if (command==tr("comment condenser la fenetre")||command==tr("comment condenser le menu")||command==tr("compacter la fenetre")){
       int random = rand() % 2 + 1;
       if(random == 1){
           client_displayMessagelist(client_generatemesage(tr("Il suffit de taper la commande /condense", "Attention bien taper la même commande!"),tr("Tchat Bot")));
       }else if(random == 2){
           ui->messagelist->append(client_generatemesage(tr("Tu peux faire clique droit sur l'icône en bas à droite dans ta barre des tâches -> Condenser la fenêtre"),tr("Tchat Bot")));
       }
   }
   }else{
      client_displayMessagelist(client_generatemesage(tr("Je suis desolé, mais je n'ai pas compris votre demande, vérifiez l'orthographe."),tr("Tchat Bot")));
  }
}
//serveur
void Widget::client_connectto(QString ip, int port)
{
    client_displayMessagelist(client_generatemesage(tr("Tentative de connexion en cours..."),tr("Tchat Bot")));
    client_changestateconnectbutton(false);
    socket->abort();
    socket->connectToHost(ip, port);
    client_displayconnectlabel(tr("<font color=\"#894B23\">Connexion lancée</font>"));
}
void Widget::client_connected()
{
    QString textmessage = client_generatemesage(tr("Connexion établie!"), tr("Tchat Bot"));
    client_sentdatamap("connection");
    client_displayMessagelist(textmessage);
    client_changestateconnectbutton(true);
    client_displayconnectlabel(tr("<font color=\"#70AD47\">Connecté</font>"));
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
void Widget::client_disconnect()
{
    QString textmessage = client_generatemesage(tr("Déconnecté du serveur"),tr("Tchat Bot"));
    client_displayconnectlabel(tr("<font color=\"#ff0000\">Déconnecté</font>"));
    client_displayMessagelist(textmessage);
    client_changestateconnectbutton(true);
}
void Widget::client_socketerror(QAbstractSocket::SocketError erreur)
{
    client_displayconnectlabel(tr("<font color=\"#ff0000\">Déconnecté</font>"));
    switch(erreur) // On affiche un message diff?rent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Le serveur n'a pas pu être trouvé. Vérifiez l'adresse et le pin."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::ConnectionRefusedError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Le serveur a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'adresse et le pin."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::RemoteHostClosedError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Le serveur a coupé la connexion."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::SocketAccessError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: L'opération a échoué car l'application ne dispose pas des privilèges requis."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;
        case QAbstractSocket::SocketResourceError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Le système local a manqué de ressources."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::SocketTimeoutError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: L'opération a expirée."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::DatagramTooLargeError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Le datagramme était plus grand que la limite du système d'exploitation (qui peut être aussi basse que 8192 octets)."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;
        case QAbstractSocket::NetworkError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Une erreur s'est produite avec le réseau ."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::UnsupportedSocketOperationError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: L'opération de socket demandée n'est pas prise en charge par le système d'exploitation."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::ProxyAuthenticationRequiredError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Le proxy requiert une authentification."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::ProxyConnectionRefusedError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Impossible de contacter le serveur proxy car la connexion à celui-ci a été refusée."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::ProxyConnectionClosedError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: La connexion au serveur proxy a été fermée de manière inattendue."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::ProxyConnectionTimeoutError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: La connexion au serveur proxy a expiré ou le serveur proxy a cessé de répondre lors de la phase d'authentification."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::ProxyNotFoundError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Le proxy est introuvable."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::ProxyProtocolError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: La connexion avec le serveur proxy a échouée, car la réponse de celui-ci n'a pas pu être comprise."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::OperationError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Une opération a été tentée alors que le socket était dans un état qui ne l'autorisait pas."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::TemporaryError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Une erreur temporaire s'est produite (Réssayer dans un moment.)."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

        case QAbstractSocket::UnknownSocketError:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur: Une erreur non identifiée s'est produite."),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
        break;

    default:
            client_displayMessagelist(client_generatemesage(QObject::tr("Erreur : ") + socket->errorString(),tr("System Tchat Bot")));
            client_changestateconnectbutton(true);
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
    sendmap["pseudo"]=client_returnpseudo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    client_sentdatamap(sendmap);

}
void Widget::client_sentdatamap(const QString type, QString message, QString pseudo, QDateTime seconde, QDateTime minute, QDateTime heures, QDateTime NoJour, QDate jour){
    QMap<QString,QString> sendmap;
    sendmap["type"]=type;
    sendmap["message"]=message;
    sendmap["pseudo"]=pseudo;
    sendmap["secondofsending"]=seconde.toString();
    sendmap["minuteofsending"]=minute.toString();
    sendmap["sendingtime"]=heures.toString();
    sendmap["sendingdate"]=NoJour.toString();
    sendmap["shippingday"]=jour.toString();
    client_sentdatamap(sendmap);
}
void Widget::client_sentdatamap(const QString type, QString message, QString pseudo){
    QMap<QString,QString> sendmap;
    sendmap["type"]=type;
    sendmap["message"]=message;
    sendmap["pseudo"]=pseudo;
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
    sendmap["pseudo"]=client_returnpseudo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    client_sentdatamap(sendmap);
}
void Widget::client_sentcommande(const QString commande){
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=commande;
    sendmap["pseudo"]=client_returnpseudo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    client_sentdatamap(sendmap);
}
void Widget::client_sentcommande(const QString commande, QString arg){
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=commande;
    sendmap["arg"]=arg;
    sendmap["pseudo"]=client_returnpseudo();
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
        // Si on arrive jusqu'? cette ligne, on peut récupérer le message entier
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
        ui->clientlist->addItem(message["pseudo"]);
        ++nbuser;
        if(nbuser==10){
            settings->setValue("succes/10userSimultaneously", true);
        }else if(nbuser==30){
            settings->setValue("succes/30userSimultaneously", true);
        }else if(nbuser==100){
            settings->setValue("succes/100userSimultaneously", true);
        }
    }else{
        QMessageBox::critical(this, tr("Erreur"), tr("Un paquet a été recu mais l'indentificateur : ") + message["type"] + tr(" est inconnu."));
    }

}
void Widget::client_processcomand(QMap<QString, QString> commend)
{
    if (commend["message"] == "pseudo?"){
        client_sentcommande("pseudo_", client_returnpseudo());
    }else if (commend["message"]=="version?"){
        client_sentcommande("version",version);
    }else if (commend["message"]=="pseudoanonymousinvalid"){
        QMessageBox::critical(this, tr("Erreur"), tr("Il vous faut un pseudo pour vous connecter (Anonymous est interdit)."));
    }else if(commend["message"]=="pseudoalreadyuse"){
        QMessageBox::critical(this, tr("Erreur"), tr("Un autre client porte déjà ce pseudo. Veuillez changer de pseudo pour vous connecter."));
    }else if(commend["message"]=="pseudoresembling"){
        QMessageBox::critical(this, tr("Erreur"), tr("Un autre client porte déjà un pseudo ressemblant. Veuillez changer de pseudo pour vous connecter."));
    }else if (commend["message"]=="update_") {
        client_displayMessagelist(commend["arg"]);
    }else if (commend["message"]=="isconnected"){
        ui->clientlist->addItem(commend["arg"]);
        ++nbuser;
    }else if(commend["message"]=="disconnecting"){
        if(ui->clientlist->findItems(commend["arg"],Qt::MatchCaseSensitive).size()==1){
            ui->clientlist->removeItemWidget(ui->clientlist->findItems(commend["arg"],Qt::MatchCaseSensitive)[1]); //on suprime le nom specifier
            QMessageBox::critical(this, tr("Suppression de client"), tr("Le client vient d'être supprimé."));
        }else{
            for (int compteur {ui->clientlist->findItems(commend["arg"],Qt::MatchCaseSensitive).size()-1}; compteur > 0; --compteur) //tan que des utilistateur porte le nom specifier
            {
                ui->clientlist->removeItemWidget(ui->clientlist->findItems(commend["arg"],Qt::MatchCaseSensitive)[1]); //on suprime le nom specifier
                QMessageBox::critical(this, tr("Suppression de client"), tr("Le client vient d'être supprimé."));
                --nbuser;
            }
        }
    }else{
        QMessageBox::critical(this, tr("Erreur"), tr("Un paquet de comande a été reçu mais la commande est incomprise."));
    }
}
QString Widget::client_generatedate()
{
    QString heures = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString Date = QDateTime::currentDateTime().toString(" dd MM yyyy");
    QDateTime::fromString(heures, "hh:mm:ss");
    return(tr("<span style=\"font-size: 10px\"> Le ")+Date+tr("</span> <span style=\"font-size: 10px\">à ")+heures+tr(" </span><br/>"));

}
QString Widget::client_generatedate(QMap<QString, QString> date)
{
    return(tr("<span style=\"font-size: 10px\"> Le ")+date["shippingday"]+" "+date["sendingdate"]+"/"+date["shippingmonth"]+"/"+date["shippingyears"] +tr("</span> <span style=\"font-size: 10px\"> à ")+date["sendingtime"]+":"+date["minuteofsending"]+tr(" </span><br/>"));

}
QString Widget::client_generatemesage(QString message, QString pseudo)
{
    if(pseudo == "" ||pseudo == " "){
        pseudo = "anonymous";
    }
    return(tr("<span style=\"font-size: 12px; font-weight: bold;\">")+pseudo+tr("</span>")+client_generatedate()+tr("<span style=\"font-size: 14px; \">")+message+tr("</span><br/><br/>"));
}
QString Widget::client_generatemesage(QMap<QString, QString> message){
    if(message["pseudo"] == "" ||message["pseudo"] == " "){
        message["pseudo"] = "anonymous";
    }
    return(tr("<span style=\"font-size: 12px; font-weight: bold;\">")+message["pseudo"]+tr("</span>")+client_generatedate(message)+tr("<span style=\"font-size: 14px; \">")+message["message"]+tr("</span><br/><br/>"));
}

void Widget::on_pseudo_editingFinished()
{
    client_sentcommande("change_psedo",ui->psedo->text());
}

#include "server.h"
#include "main.cpp"
server::server()
{
   startserveur();// j'ai peur que le serveur se start trop tard
   version = "4.3.0";
   messagesize = 0;
   //selection de la couleur du theme
   /*parametre* parametres = new parametre();
   condenser = false;
   qApp->setPalette(parametres->starttheme());*/
}
void server::startserveur()
{
    m_serveur = new QTcpServer(nullptr);
    if (!m_serveur->listen(QHostAddress::Any, 2048)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 2048
    {
        // Si le serveur n'a pas été démarré correctement
        if (!m_serveur->listen(QHostAddress::Any)) // Démarrage du serveur sur toutes les IP disponibles
        {
            // Si le serveur n'a pas été démarré correctement
            server_displayMessagelist("the server has not starting because" + m_serveur->errorString());
        }
    }
    else
    {
        // Si le serveur a été démarré correctement
        server_displayMessagelist("the serveur has starting in port " + QString::number(m_serveur->serverPort()) + "Clients can now connect.");
        QObject::connect(m_serveur, &QTcpServer::newConnection, this, &server::server_newconect);
    }
}

void server::server_displayMessagelist(QString message)
{
    pinup(message);
}
//serveur
void server::server_sentmessagetoall(const QMap<QString, QString> &message)
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
void server::server_sentmessageto(const QMap<QString, QString> &message, int NoUtilisateur)
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
void server::server_sentmessagetoall(const QString type, QString message, QString psedo){
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
    server_sentmessagetoall(sendmap);
}
void server::server_sentmessageto(const QString &message, int NoUtilisateur)
{
    QMap<QString,QString> sendmap;
    sendmap["type"]="msg";
    sendmap["message"]=message;
    sendmap["psedo"]="serveur"+m_serveur->serverAddress().toString();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    server_sentmessageto(sendmap,NoUtilisateur);
}
void server::server_sentcomandto(const QString &message ,int usernaime)
{
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=message;
    sendmap["psedo"]="serveur"+m_serveur->serverAddress().toString();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    server_sentmessageto(sendmap,usernaime);

}
void server::server_sentcomandto(const QString &message,QString arg ,int usernaime)
{
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=message;
    sendmap["arg"]=arg;
    sendmap["psedo"]="serveur"+m_serveur->serverAddress().toString();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    server_sentmessageto(sendmap,usernaime);

}
void server::serveur_sentcommende(const QString commende, QString arg){
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=commende;
    sendmap["arg"]=arg;
    sendmap["psedo"]="serveur"+m_serveur->serverAddress().toString();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    server_sentmessagetoall(sendmap);
}
void server::server_newconect()
{
    utilisateur* newClient = new utilisateur(m_serveur->nextPendingConnection());
    clientsList.append(newClient);
    QObject::connect(newClient->getSocket(), &QAbstractSocket::readyRead, this, &server::server_datareceived);
    QObject::connect(newClient->getSocket(), &QAbstractSocket::disconnected, this, &server::server_disconnectclients);
    //server_sentcomandto("psedo?",size));
    //server_sentcomandto("vertion?",size);
}
void server::server_datareceived()
{
    int index = server_findIndex(qobject_cast<QTcpSocket *>(sender()));
      utilisateur* sendingClient = clientsList[index];
      QTcpSocket* socket = sendingClient->getSocket();

      if(socket == nullptr) {
        server_displayMessagelist("error searching of client who has send paket");
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
                    server_sentmessageto(server_generatemesage(tr("erreur vous ne pouvez pas envoyer de message au serveur pour le moment le serveur nautorise pas le psedo: ")+sendingClient->getpseudo(),tr("serveur bot")),index);
                    server_sentcomandto("psedo?",index);
                    return;
                }else if(sendingClient->getpseudo()==""){
                    server_sentmessageto(server_generatemesage(tr("erreur vous ne pouvez pas envoyer de message au serveur pour le moment le serveur nautorise pas les psedo vide"),tr("serveur bot")),index);
                    server_sentcomandto("psedo?",index);
                    return;
                }else if(sendingClient->getversion()!="4.1.0"){
                    server_sentmessageto(server_generatemesage(tr("erreur vous ne pouvez pas envoyer de message. le serveur a pas une vertion du tchat compatible avec la vautre"),tr("serveur bot")),index);
                    server_sentcomandto("vertion?",index);
                    return;
                }else{
                    server_sentmessageto(tr("erreur indefini sur lidantfication de ton satut info de debug : psedo: ")+sendingClient->getpseudo()+tr(" vertion ")+sendingClient->getversion(),index);
                    return;
                }
            }else{*/
                server_sentmessagetoall(message);
                //server_writetofile(message);
            }

        //}else{
            //QMessageBox::critical(this, tr("erreur"), tr("un packet de comande a été recu mais la l'idantificateur ")+ message["type"] +tr("est incompri."));
            //server_displayMessagelist(server_generatemesage(tr("un packet de comande a été recu mais la l'idantificateur ")+ message["type"] +tr("est incompri."),tr("serveur bot")));
        }
        sendingClient->setmessageSize(static_cast<quint16>(0));
    }
//}
void server::server_disconnectclients()
{
    QTcpSocket* disconnectingClientSocket = qobject_cast<QTcpSocket*>(sender());

    if(disconnectingClientSocket == nullptr) //Error
    {
        pinup("the client has not be delet");
        return;
    }

    int index = server_findIndex(disconnectingClientSocket);
    utilisateur* disconnectingClient = clientsList[index];

    server_sentmessagetoall("msg",disconnectingClient->getpseudo()+tr("</strong> vient de se déconnecter !"),tr("serveur bot"));

    clientsList.removeOne(disconnectingClient);
    delete disconnectingClient;
}
int server::server_findIndex(QTcpSocket* socket)
{
    int index = 0;

    while(clientsList[index]->getSocket() != socket)
    {
        index++;
    }

    return index;
}
/*void server::server_writetofile(QMap<QString, QString> FluxFile)
{
    ++NbOfMessage;
    saveMessage[NbOfMessage]=FluxFile;
    QFile file("chat.dat");
    if (!file.open(QIODevice::WriteOnly)){
            server_displayMessagelist(server_generatemesage(tr("il est imposible d'ecrire dans le fichier"),tr("chatbot")));
            return;
        }
    QDataStream out(&file);
    out << saveMessage;
}*/
void server::server_processcomand(QMap<QString, QString> command, int noclient)
{
    if (command["message"]=="psedo"){
        if(command["arg"]=="anonimous"){
            server_sentcomandto("pesdoAnonimousinvalid", noclient);
            return;
        }else{
            for(int i = 1; i < clientsList.size(); i++)
            {
                if(clientsList[i]->getpseudo()==command["psedo"] && i != noclient){
                    server_sentcomandto("psedoalreadyuse",noclient);
                    return;
                }else if(clientsList[i]->getpseudo().remove(" ")==command.remove(" ") && i != noclient){
                    server_sentcomandto("pseudoresembling",noclient);
                    return;
                }
            }
            clientsList[noclient]->editpsedo(command["arg"]);
            //server_sentmessageto(server_recoverallfile(),clientsList.size());
            srand (time(NULL));
            int random = rand() % 4 + 1;
            if(random == 1){
                server_sentmessagetoall("msg",clientsList[noclient]->getpseudo() + tr(" est connecter"),tr("serveur chat bot"));
            }else if(random == 2){
                 server_sentmessagetoall("msg",clientsList[noclient]->getpseudo() + tr(" vien d'ariver dans le salon"),tr("serveur chat bot"));
            }else if(random == 3){
                server_sentmessagetoall("msg",tr("bonjour ")+clientsList[noclient]->getpseudo() + tr(" vien de nous rejoindre"),tr("serveur chat bot"));
            }else if(random == 4){
                server_sentmessagetoall("msg",tr("il ne nous manquer plus que ")+clientsList[noclient]->getpseudo()+ tr(" heureusement il nous a rejoint"),tr("serveur chat bot"));
            }
            serveur_sentcommende("isconnected", clientsList[noclient]->getpseudo());
            if(noclient==0){return;}
            for(int i = 1; i < clientsList.size(); i++)
            {
                if(i==noclient){i++;}
                if(i>clientsList.size()){return;}
                server_sentcomandto("isconnected", clientsList[i-1]->getpseudo(),noclient);
            }
        }

    }else if(command["message"]=="vertion"){
        clientsList[noclient]->editvertion(command["arg"]);
    }else if (command["message"]=="updating") {
        //server_sentcomandto("update_"+server_recoverallfile(),noclient);
    }else{
        pinup("the packet of commend is not known");
    }
}
/*QMap<int,QMap<QString,QString>> server::server_recoverallfile()
{
    QFile fichier("chat.dat");
    QMap<int,QMap<QString,QString>> texte;
   if(fichier.open(QIODevice::ReadOnly))
   {
       QDataStream flux(&fichier);
       texte << flux;
       return texte;
   }
   else
   {
       server_displayMessagelist(server_generatemesage(tr("le fichier et inaxecible"), tr("chat bot")));

   }
}*/
QString server::server_generatedate()
{
    QString heurs = QDateTime::currentDateTime().toString(" hh:mm:ss ");
    QString Date = QDateTime::currentDateTime().toString(" dd MM yyyy ");
    QDateTime::fromString(heurs, " hh:mm:ss ");
    return("<span style=\"font-size: 10px\"> Le "+Date+"</span> <span style=\"font-size: 10px\">à "+heurs+" </span><br/>");
}
QString server::server_generatemesage(QString message, QString psedo)
{
    return("<span style=\"font-size: 12px; color:#000000; font-weight: bold;\">")+psedo+"</span>"+server_generatedate()+"<span style=\"font-size: 14px; color:#2F2F2F\">"+message+"</span><br/><br/>";
}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->moveEvent(0);
    QString name = qgetenv("USER");
    if (name.isEmpty())
        name = qgetenv("USERNAME");
    ui->psedo->setText(name);
    path = ":/sound/notifdefault.wav";
    readarg();
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
    QIcon icon(":/images/Ananta.png");
    sticon->setIcon(icon); // On assigne une image à notre icône
    sticon->show(); // On affiche l'icône
    connect(actTexte1, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(condense, &QAction::triggered, this, &Widget::condesed);
    condenser = false;
    socket = new QTcpSocket; //serveur
    connect(socket, &QTcpSocket::readyRead, this ,&Widget::datareceived);
    connect(socket, &QTcpSocket::connected,this,&Widget::connected);
    connect(socket, &QTcpSocket::disconnected,this,&Widget::desconnect);
    connect(socket, &QTcpSocket::errorOccurred, this, &Widget::socketerror);
    messagesize = 0;
    parametre *parametres = new parametre();
    qApp->setPalette(parametres->starttheme());
    version = "4.3.0";
}

Widget::~Widget()
{
    delete ui;
    sticon->setVisible(false);
}
void Widget::readarg()
{
    QFile file("start.temp");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this,tr("auto remplissage"),tr("le fichier de remplissage automatique n'est pas disponiblele remplissage doit etre fait manuellement"));
        return;
    }
    QTextStream in(&file);
    ui->serveurip->setText(in.readLine());
    ui->serveurport->setValue(in.readLine().toInt());
}
void Widget::displayMessagelist(QString message)
{
    if(parametres.settings["notification sonore"]=="true")
    {
        QSound::play(path);
    }
    if(parametres.settings["notification visuelle"]=="true")
    {
        if(QApplication::activeWindow()){

        }else{
            auto text = QTextDocumentFragment::fromHtml(message);
            qDebug()  << tr("message:") << text.toPlainText();
            sticon->showMessage("",text.toPlainText(),QSystemTrayIcon::Information,2000);
        }
        QApplication::alert(this);//je fait clignotée la fenetre
    }
    ui->messagelist->append(message);
}
void Widget::changestateconnectbuton(bool state)
{
 ui->conectbuton->setEnabled(state);
}
void Widget::condesed(){
    if (socket->state()){
        if (condenser == false)
        {
            ui->label_5->setVisible(false);
            ui->serveurip->setVisible(false);
            ui->psedo->setVisible(false);
            ui->label_psedo->setVisible(false);
            ui->label_4->setVisible(false);
            ui->serveurport->setVisible(false);
            ui->parametrebuton->setVisible(false);
            ui->clientlist->setVisible(false);
            ui->label_message_3->setVisible(false);
            ui->conectbuton->setVisible(false);
            ui->label_6->setVisible(false);
            ui->conectstatelabel->setVisible(false);
            this->setWindowFlags(Qt::WindowStaysOnTopHint);
            this->show();
            condenser = true;
            resize(610,89);
        }else if (condenser == true){
            ui->label_5->setVisible(true);
            ui->serveurip->setVisible(true);
            ui->psedo->setVisible(true);
            ui->label_psedo->setVisible(true);
            ui->label_4->setVisible(true);
            ui->serveurport->setVisible(true);
            ui->parametrebuton->setVisible(true);
            ui->clientlist->setVisible(true);
            ui->label_message_3->setVisible(true);
            ui->conectbuton->setVisible(true);
            ui->label_6->setVisible(true);
            ui->conectstatelabel->setVisible(true);
            this->setWindowFlags(Qt::Window);
            condenser = false;
            this->show();
        }else{
            QMessageBox::critical(this,tr("bool condesed"),tr("erreur un bool ne pet pas avoir tois etat signalez le dans: parametre  puis discord", "oui oui il faut traduire ca au cas ou un bool ait trois etat"));
        }
    }else{
        QMessageBox::information(this,tr("passage en mode condensée"),tr("vous ne pouvez passer l'app en mode condensée que une fois connecter"));

    }
}
void Widget::changetransparency(Qt::ApplicationState state){
    if(state == Qt::ApplicationInactive){
        if(condenser){
            this->setWindowOpacity(parametres.settings["transparency"].toDouble());
        }
    }else if(state == Qt::ApplicationActive){
        this->setWindowOpacity(1);
    }

}
QString Widget::returnpsedo()
{
    return ui->psedo->text();
}
void Widget::on_conectbuton_clicked()
{
    if(ui->psedo->text()==""||ui->psedo->text()==" "||ui->psedo->text()=="anonymous"){
        QMessageBox::critical(this,tr("psedo invalid"),tr("vous ne pouvez avoir anonymous ou aucun psedo"));
        return;
    }
    connectto(ui->serveurip->text(), ui->serveurport->value());
    ui->clientlist->clear();
    displayconnectlabel(tr("<font color=\"#ff0000\">Déconnecté</font>"));
}
void Widget::displayconnectlabel(QString text)
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
    //supression des formule de politesse des point et des majuscule
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
        processechatbot(message);
    }else if(message.startsWith(tr("chat bot"))){
        message.remove(tr("chat bot"));
        processechatbot(message);
    }else if(message.startsWith(tr("ananta systeme"))){
        message.remove(tr("ananta systeme"));
        processechatbot(message);
    }else if(message.startsWith(tr("ananta système"))){
        message.remove(tr("ananta système"));
        processechatbot(message);
    }else{
        sentdatamap("msg",msg);
    }
    ui->mesage->clear();
}
void Widget::processechatbot(QString command)
{
    srand (time(NULL));
   //reponse pré faite
   if (command==tr("bonjour")||command==tr("salut")||command==tr("hello")){//posibilier de question
       int random = rand() % 5 + 1;//on fait l'aleatoire
       if(random == 1){
           ui->messagelist->append(generatemesage(tr("bonjour") + ui->psedo->text()+".",tr("chat bot")));
       }else if(random == 2){
           ui->messagelist->append(generatemesage(tr("salut") + ui->psedo->text()+".",tr("chat bot")));
       }else if(random == 3){
           ui->messagelist->append(generatemesage(tr("salut") + ui->psedo->text()+".",tr("chat bot")));
       }else if(random == 4){
           ui->messagelist->append(generatemesage(tr("hello") + ui->psedo->text()+".",tr("chat bot")));
       }else if(random == 5){
           ui->messagelist->append(generatemesage(tr("hello👋") + ui->psedo->text()+".",tr("chat bot")));
       }
   }else if (command==tr("comment t'apelle tu")||command==tr("quel est ton nom")){
       int random = rand() % 2 + 1;
       if(random == 1){
           ui->messagelist->append(generatemesage(tr("tu peut mapeller ANANTA SYSTÈME."),tr("chat bot")));
       }else if(random == 2){
           ui->messagelist->append(generatemesage(tr("tu peut mapeller chat bot."),tr("chat bot")));
       }
   }else if (command==tr("qui est tu")){
       ui->messagelist->append(generatemesage(tr("je suis le chat bot crée par ananta systeme je suis encors tres inachever."),tr("chat bot")));
   }else if (command=="clear"){
       ui->messagelist->clear();
   }else if (command=="actualise"||command=="update"){
        sentcommende("updating");
   }else if (command==tr("merci")){
       int random = rand() % 7 + 1;
       if(random == 1){
           ui->messagelist->append(generatemesage(tr("de rien 😀"),tr("chat bot")));
       }else if(random == 2){
           ui->messagelist->append(generatemesage(tr("tout le plaisire et pour moi 😀"),tr("chat bot")));
       }else if(random == 3){
           ui->messagelist->append(generatemesage(tr("tout le plaisire et pour moi!"),tr("chat bot")));
       }else if(random == 3){
           ui->messagelist->append(generatemesage(tr("de rien !"),tr("chat bot")));
       }else if(random == 4){
           ui->messagelist->append(generatemesage(tr("mais je suis la pour ca bien sur 😀"),tr("chat bot")));
       }else if(random == 5){
           ui->messagelist->append(generatemesage(tr("mais je suis la pour ca bien sur !"),tr("chat bot")));
       }else if (random == 6){
            ui->messagelist->append(generatemesage(tr("quand tu ne me parle pas je fait que des acion repetitive... recevoir des message te les aficher😥"),tr("chat bot")));
       }else if (random == 7){
            ui->messagelist->append(generatemesage(tr("quand tu ne me parle pas je m'enuie 😥"),tr("chat bot")));
   }else if (command==tr("condenses")||command==tr("condense")||command==tr("condense menu")){
       condesed();
    }else if (command==tr("comment condenser la fenetre")||command==tr("comment condenser le menu")||command==tr("compacter la fenetre")){
       int random = rand() % 3 + 1;
       if(random == 1){
           displayMessagelist(generatemesage(tr("il sufit de taper la commende /condense", "atension a metre la meme sytax que la ligne de juste au dessu"),tr("chat bot")));
       }else if(random == 2){
           ui->messagelist->append(generatemesage(tr("tu peut allez dans parametre et cliquer sur passer en mode condensé"),tr("chat bot")));
       }else if(random == 3){
           ui->messagelist->append(generatemesage(tr("il te sufit de faire clique droit sur l'icone dans la bare des tache et cliquer sur passer en mode condensé"),tr("chat bot")));
       }
   }
   }else{
      displayMessagelist(generatemesage(tr("desolée je n'ai pas compris"),tr("chat bot")));
  }
}
//serveur
void Widget::connectto(QString ip, int port)
{
    displayMessagelist(generatemesage(tr("tentative de connexion en cour"),tr("chat bot")));
    changestateconnectbuton(false);
    socket->abort();
    socket->connectToHost(ip, port);
    displayconnectlabel(tr("<font color=\"#894B23\">tenetative lancé</font>"));
}
void Widget::connected()
{
    sentcommende("vertion", version);
    sentcommende("psedo",returnpsedo());
    displayMessagelist(generatemesage(tr("conexion reusi"), tr("chat bot")));
    changestateconnectbuton(true);
     displayconnectlabel(tr("<font color=\"#70AD47\">connecté</font>"));
}
void Widget::desconnect()
{
    QString textmessage = generatemesage(tr("déconecter du serveur"),tr("chat bot"));
    displayconnectlabel(tr("<font color=\"#ff0000\">Déconnecté</font>"));
    displayMessagelist(textmessage);
    changestateconnectbuton(true);
}
void Widget::socketerror(QAbstractSocket::SocketError erreur)
{
    displayconnectlabel(tr("<font color=\"#ff0000\">Déconnecté</font>"));
    switch(erreur) // On affiche un message diff?rent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            displayMessagelist(generatemesage(QObject::tr("ERREUR : le serveur primaire n'a pas pu étre trouvé. Vérifiez le nom du serveur et le mot de passe."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::ConnectionRefusedError:
            displayMessagelist(generatemesage(QObject::tr("ERREUR : le serveur primaire a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP et le port."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::RemoteHostClosedError:
            displayMessagelist(generatemesage(QObject::tr("ERREUR : le serveur primaire a coupé la connexion."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::SocketAccessError:
            displayMessagelist(generatemesage(QObject::tr("L'opération a échoué car l'application ne dispose pas des privilèges requis."),tr("chat bot")));
            changestateconnectbuton(true);
        break;
        case QAbstractSocket::SocketResourceError:
            displayMessagelist(generatemesage(QObject::tr("Le système local a manqué de ressources (par exemple, trop de sockets)."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::SocketTimeoutError:
            displayMessagelist(generatemesage(QObject::tr("loperation a expirée"),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::DatagramTooLargeError:
            displayMessagelist(generatemesage(QObject::tr("Le datagramme était plus grand que la limite du système d'exploitation (qui peut être aussi basse que 8192 octets)"),tr("chat bot")));
            changestateconnectbuton(true);
        break;
        case QAbstractSocket::NetworkError:
            displayMessagelist(generatemesage(QObject::tr("Une erreur s'est produite avec le réseau (par exemple, le câble réseau a été \"accidentellement\" débranché)."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::UnsupportedSocketOperationError:
            displayMessagelist(generatemesage(QObject::tr("L'opération de socket demandée n'est pas prise en charge par le système d'exploitation local (par exemple, absence de prise en charge d'IPv6)."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyAuthenticationRequiredError:
            displayMessagelist(generatemesage(QObject::tr(" le proxy requiert une authentification."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyConnectionRefusedError:
            displayMessagelist(generatemesage(QObject::tr("Impossible de contacter le serveur proxy car la connexion à ce serveur a été refusée"),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyConnectionClosedError:
            displayMessagelist(generatemesage(QObject::tr("La connexion au serveur proxy a été fermée de manière inattendue (avant que la connexion au pair final ne soit établie)"),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyConnectionTimeoutError:
            displayMessagelist(generatemesage(QObject::tr("La connexion au serveur proxy a expiré ou le serveur proxy a cessé de répondre lors de la phase d'authentification."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyNotFoundError:
            displayMessagelist(generatemesage(QObject::tr("le proxi est inrouvable"),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::ProxyProtocolError:
            displayMessagelist(generatemesage(QObject::tr("La négociation de connexion avec le serveur proxy a échoué, car la réponse du serveur proxy n'a pas pu être comprise."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::OperationError:
            displayMessagelist(generatemesage(QObject::tr("Une opération a été tentée alors que le socket était dans un état qui ne l'autorisait pas."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::TemporaryError:
            displayMessagelist(generatemesage(QObject::tr("Une erreur temporaire s'est produite (par exemple, l'opération bloquerait et le socket n'est pas bloquant)."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

        case QAbstractSocket::UnknownSocketError:
            displayMessagelist(generatemesage(QObject::tr("Une erreur non identifiée s'est produite."),tr("chat bot")));
            changestateconnectbuton(true);
        break;

    default:
            displayMessagelist(generatemesage(QObject::tr("ERREUR : ") + socket->errorString(),tr("chat bot")));
            changestateconnectbuton(true);
        break;
    }
}
// optionelle
void Widget::sentdatamap(const QMap<QString,QString> sendmap)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << sendmap;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    socket->write(paquet); // On envoie le paquet
}
void Widget::sentdatamap(const QString type, QString message, QString psedo, QDateTime seconde, QDateTime minute, QDateTime heurs, QDateTime NoJour, QDate jour){
    QMap<QString,QString> sendmap;
    sendmap["type"]=type;
    sendmap["message"]=message;
    sendmap["psedo"]=psedo;
    sendmap["secondofsending"]=seconde.toString();
    sendmap["minuteofsending"]=minute.toString();
    sendmap["sendingtime"]=heurs.toString();
    sendmap["sendingdate"]=NoJour.toString();
    sendmap["shippingday"]=jour.toString();
    sentdatamap(sendmap);
}
void Widget::sentdatamap(const QString type, QString message, QString psedo){
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
    sentdatamap(sendmap);
}
void Widget::sentdatamap(const QString type, QString message){
    QMap<QString,QString> sendmap;
    sendmap["type"]=type;
    sendmap["message"]=message;
    sendmap["psedo"]=returnpsedo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    sentdatamap(sendmap);
}
void Widget::sentcommende(const QString commende){
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=commende;
    sendmap["psedo"]=returnpsedo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    sentdatamap(sendmap);
}
void Widget::sentcommende(const QString commende, QString arg){
    QMap<QString,QString> sendmap;
    sendmap["type"]="cmd";
    sendmap["message"]=commende;
    sendmap["arg"]=arg;
    sendmap["psedo"]=returnpsedo();
    sendmap["secondofsending"]=QDateTime::currentDateTime().toString("ss");;
    sendmap["minuteofsending"]=QDateTime::currentDateTime().toString("mm");;
    sendmap["sendingtime"]=QDateTime::currentDateTime().toString("hh");
    sendmap["sendingdate"]=QDateTime::currentDateTime().toString("d");
    sendmap["shippingday"]=QDateTime::currentDateTime().toString("dddd");
    sendmap["shippingmonth"]=QDateTime::currentDateTime().toString("MMMM");
    sendmap["shippingyears"]=QDateTime::currentDateTime().toString("yyyy");
    sentdatamap(sendmap);
}
void Widget::datareceived()
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
}
QString Widget::generatedate()
{
    QString heurs = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString Date = QDateTime::currentDateTime().toString(" dd MM yyyy");
    QDateTime::fromString(heurs, "hh:mm:ss");
    return(tr("<span style=\"font-size: 10px\"> Le ")+Date+tr("</span> <span style=\"font-size: 10px\">à ")+heurs+tr(" </span><br/>"));

}
QString Widget::generatedate(QMap<QString, QString> date)
{
        return(tr("<span style=\"font-size: 10px\"> Le ")+date["shippingday"]+" "+date["sendingdate"]+"/"+date["shippingmonth"]+"/"+date["shippingyears"] +tr("</span> <span style=\"font-size: 10px\"> à ")+date["sendingtime"]+":"+date["minuteofsending"]+tr(" </span><br/>"));
}
QString Widget::generatemesage(QString message, QString psedo)
{
    if(psedo == "" ||psedo == " "){
        psedo = "anonymous";
    }
    return(tr("<span style=\"font-size: 12px; font-weight: bold;\">")+psedo+tr("</span>")+generatedate()+tr("<span style=\"font-size: 14px; \">")+message+tr("</span><br/><br/>"));
}
QString Widget::generatemesage(QMap<QString, QString> message){
    if(message["psedo"] == "" ||message["psedo"] == " "){
        message["psedo"] = "anonymous";
    }
    return(tr("<span style=\"font-size: 12px; font-weight: bold;\">")+message["psedo"]+tr("</span>")+generatedate(message)+tr("<span style=\"font-size: 14px; \">")+message["message"]+tr("</span><br/><br/>"));
}
void Widget::on_parametrebuton_clicked()
{
    parametres.show();
}

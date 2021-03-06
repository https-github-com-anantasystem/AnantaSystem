#include "utilisateur.h"

utilisateur::utilisateur()
{
    pseudo = "anonymous";
    socket = new QTcpSocket;
    messageSize = 0;
    vertion = "0";
}
utilisateur::utilisateur(QTcpSocket* socketToServer)
{
    pseudo = "anonymous";
    socket = socketToServer;
    messageSize = 0;
    vertion = "0";
}
utilisateur::utilisateur(QString pseudo, QTcpSocket* socket)
{
    this->pseudo = pseudo;
    this->socket = socket;
    messageSize = 0;
    vertion = "0";
}
QTcpSocket* utilisateur::getSocket()
{
    return socket;
}

void utilisateur::setmessageSize(quint16 size)
{
    messageSize = size;
}
quint16 utilisateur::getmessageSize()
{
    return messageSize;
}
QString utilisateur::getpseudo()
{
    return pseudo;
}
QString utilisateur::getversion()
{
    return vertion;
}
void utilisateur::editvertion(QString newvertion){
    vertion = newvertion;
}
void utilisateur::editpsedo(QString newpsedo)
{
    pseudo = newpsedo;
}
bool utilisateur::isconnecteed()
{
    if(getpseudo()=="Anonymous"&&vertion!=0){
        return false;
    }else{
        return true;
    }
}
utilisateur::~utilisateur()
{
    socket->deleteLater();
}

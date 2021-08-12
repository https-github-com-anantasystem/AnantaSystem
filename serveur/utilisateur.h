#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QObject>
#include <QTcpSocket>

class utilisateur: public QObject
{
public:
    utilisateur();
    utilisateur(QString pseudo, QTcpSocket* socket);
    utilisateur(QTcpSocket* socket);
    void editpsedo(QString newpsedo);
    void editvertion(QString newvertion);
    void setmessageSize(quint16 size);
    QTcpSocket* getSocket();
    quint16 getmessageSize();
    QString getpseudo();
    QString getversion();
    bool isconnecteed();
    ~utilisateur();
private:
    QString vertion;
    QString pseudo;
    QTcpSocket* socket;
    quint16 messageSize;
};
#endif // UTILISATEUR_H

#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QDataStream>
#include <QDateTime>
#include <QWidget>
#include "utilisateur.h"

class server : public QObject
{
    Q_OBJECT

public:
    server();
private:
    QString version;
    QTcpServer *m_serveur;
    QList<utilisateur*> clientsList;
    int messagesize;
private slots:
    void startserveur();
    void server_displayMessagelist(QString message);
    void server_sentmessagetoall(const QMap<QString, QString> &message);
    void server_sentmessageto(const QMap<QString, QString> &messag, int NoUtilisateure);
    void server_sentmessagetoall(const QString type, QString message, QString psedo);
    void server_sentmessageto(const QString &message ,int usernaime);
    void server_sentcomandto(const QString &message ,int usernaime);
    void server_sentcomandto(const QString &message,QString arg ,int usernaime);
    void serveur_sentcommende(const QString commende, QString arg);
    void server_newconect();
    void server_datareceived();
    void server_disconnectclients();
    //void server_writetofile(QMap<QString, QString> FluxFile);
    void server_processcomand(QMap<QString, QString> command, int noclient);
    QString server_generatedate();
    QString server_generatemesage(QString message, QString psedo);
    //QMap<int,QMap<QString,QString>> server_recoverallfile();
    int server_findIndex(QTcpSocket* socket);
};

#endif // SERVER_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QStyleFactory>
#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDateTime>
#include <QMessageBox>
#include <QFile>
#include <QNetworkInterface>
#include <QSound>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTextDocumentFragment>
#include <QFileDialog>
#include <QDesktopServices>
#include <QInputDialog>
#include <QSettings>
#include "utilisateur.h"
#include "parametre.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    parametre parametres;
    Q_OBJECT

public:
    QList<QMap<QString,QString>> saveMessage;
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QString levelOfSecure;
    QSettings* settings;
    Ui::Widget *ui;
    QString version;
    bool condenser;
    QTcpServer* m_serveur;
    QList<utilisateur*> clientsList;
    int NbOfMessage;
    int nbuser;
    QSystemTrayIcon* sticon;
    QLabel *text;
    QMenu *stmenu;
    QTcpSocket *socket;
    quint16 messagesize;
private slots:
    //ui
    void startTrayIcon();
    void changetransparency(Qt::ApplicationState);
    void condesed();
    void server_displayMessagelist(QString message);
    //serveur
    void startserveur();
    void server_sentmessagetoall(const QMap<QString, QString> &message);
    void server_sentmessageto(const QMap<QString, QString> &messag, int NoUtilisateure);
    void server_sentmessagetoall(const QString type, QString message, QString pseudo);
    void server_sentmessageto(const QString &message , QString pseudo, int usernaime);
    void server_sentmessageto(const QString &message ,int usernaime);
    void server_sentcomandto(const QString &message ,int usernaime);
    void server_sentcomandto(const QString &message,QString arg ,int usernaime);
    void serveur_sentcommande(const QString commande, QString arg);
    void server_newconect();
    void server_connect(const QMap<QString, QString> &connectpack,int usernaime);
    void server_datareceived();
    void server_disconnectclients();
    void server_writetofile(QMap<QString, QString> FluxFile);
    void server_processcomand(QMap<QString, QString> command, int noclient);
    QString server_generatedate();
    QString server_generatemesage(QString message, QString pseudo);
    void server_recoverallfile();
    int server_findIndex(QTcpSocket* socket);

    //client
    void client_displayMessagelist(QString message);
    void client_changestateconnectbutton(bool state);
    void client_displayconnectlabel(QString text);
    void on_conectbutton_clicked();
    void on_sentbutton_clicked();
    void client_processechatbot(QString command);
    void client_connectto(QString ip, int port);
    void client_connected();
    void client_disconnect();
    void client_socketerror(QAbstractSocket::SocketError error);
    void client_sentdatamap(const QMap<QString,QString> sendmap);
    void client_sentdatamap(const QString type);
    void client_sentdatamap(const QString type, QString message, QString pseudo, QDateTime seconde, QDateTime minute, QDateTime heurs, QDateTime NoJour, QDate jour);
    void client_sentdatamap(const QString type, QString message, QString pseudo);
    void client_sentdatamap(const QString type, QString message);
    void client_sentcommande(const QString commande);
    void client_sentcommande(const QString commande, QString arg);
    void client_datareceived();
    void client_processthemessage(QMap<QString,QString> message);
    void client_processcomand(QMap<QString, QString> commend);
    QString client_generatedate();
    QString client_generatedate(QMap<QString, QString> date);
    QString client_generatemesage(QString message, QString pseudo);
    QString client_generatemesage(QMap<QString, QString> message);
    QString client_returnpseudo();
    void on_parametrebutton_clicked();
    void on_pseudo_editingFinished();
};
#endif // WIDGET_H

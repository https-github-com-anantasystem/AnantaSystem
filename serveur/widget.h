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
    void changetransparency(Qt::ApplicationState state);
    void condesed();
    void server_displayMessagelist(QString message);
    //serveur
    void startserveur();
    void server_sentmessagetoall(const QMap<QString, QString> &message);
    void server_sentmessageto(const QMap<QString, QString> &messag, int NoUtilisateure);
    void server_sentmessagetoall(const QString type, QString message, QString psedo);
    void server_sentmessageto(const QString &message ,int usernaime);
    void server_sentcomandto(const QString &message ,int usernaime);
    void server_sentcomandto(const QString &message,QString arg ,int usernaime);
    void serveur_sentcommende(const QString commende, QString arg);
    void server_newconect();
    void server_connect(const QMap<QString, QString> &connectpack,int usernaime);
    void server_datareceived();
    void server_disconnectclients();
    void server_writetofile(QMap<QString, QString> FluxFile);
    void server_processcomand(QMap<QString, QString> command, int noclient);
    QString server_generatedate();
    QString server_generatemesage(QString message, QString psedo);
    void server_recoverallfile();
    int server_findIndex(QTcpSocket* socket);

    //client
    void client_displayMessagelist(QString message);
    void client_changestateconnectbuton(bool state);
    void client_displayconnectlabel(QString text);
    void on_conectbuton_clicked();
    void on_sentbuton_clicked();
    void client_processechatbot(QString command);
    void client_connectto(QString ip, int port);
    void client_connected();
    void client_desconnect();
    void client_socketerror(QAbstractSocket::SocketError error);
    void client_sentdatamap(const QMap<QString,QString> sendmap);
    void client_sentdatamap(const QString type);
    void client_sentdatamap(const QString type, QString message, QString psedo, QDateTime seconde, QDateTime minute, QDateTime heurs, QDateTime NoJour, QDate jour);
    void client_sentdatamap(const QString type, QString message, QString psedo);
    void client_sentdatamap(const QString type, QString message);
    void client_sentcommende(const QString commende);
    void client_sentcommende(const QString commende, QString arg);
    void client_datareceived();
    void client_processthemessage(QMap<QString,QString> message);
    void client_processcomand(QMap<QString, QString> commend);
    QString client_generatedate();
    QString client_generatedate(QMap<QString, QString> date);
    QString client_generatemesage(QString message, QString psedo);
    QString client_generatemesage(QMap<QString, QString> message);
    QString client_returnpsedo();
    void on_parametrebuton_clicked();
};
#endif // WIDGET_H

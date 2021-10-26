/* ce projet est en test il a été consu comme si il y avait deux classe
 je voulais faire de la foward declaration mais je ne savais pas faire... donc en atendant...
ANANTA SYSTEME  tchat 4.0.-1
*/

#ifndef WIDGET_H
#define WIDGET_H
#include <QSound>
#include <QWidget>
#include <QTcpSocket>
#include <QDateTime>
#include <QMessageBox>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTextDocumentFragment>
#include <QFileDialog>
#include <QSettings>
#include <QStyleFactory>
#include <QNetworkInterface>
#include "parametre.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class Widget :public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QList<QMap<QString,QString>> saveMessage;
    parametre parametres;
private slots:
    void on_parametrebuton_2_clicked();
    void on_psedo_editingFinished();
    void on_conectbuton_clicked();
    void on_sentbuton_clicked();

private:
    QSettings* settings;
    Ui::Widget *ui;
    QString version;
    bool condenser;
    int NbOfMessage;
    int nbuser;
    QSystemTrayIcon* sticon;
    QLabel *text;
    QMenu *stmenu;
    QTcpSocket *socket;
    quint16 messagesize;
private:
    //ui
    void startTrayIcon();
    void changetransparency(Qt::ApplicationState state);
    void condesed();
    void helpcondesed();
    //client
    void autoconnect();
    void client_displayMessagelist(QString message);
    void client_changestateconnectbuton(bool state);
    void client_displayconnectlabel(QString text);
    void client_processechatbot(QString command);
    void client_connectto(QString ip, int port);
    void client_connected();
    void client_desconnect();
    void client_socketerror(QAbstractSocket::SocketError error);
    void client_sentdatamap(const QMap<QString,QString> sendmap);
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

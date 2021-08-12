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
#include <QStyleFactory>
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
private:
    Ui::Widget *ui;
    QSystemTrayIcon* sticon;
    parametre parametres;
    QLabel *text;
    QMenu *stmenu;
    bool condenser;

    QTcpSocket *socket;//serveur
    quint16 messagesize;
    QString path;
    QString version;

private :
    void readarg();
    void changetransparency(Qt::ApplicationState state);
    void displayMessagelist(QString message);
    void changestateconnectbuton(bool state);
    void displayconnectlabel(QString text);
    void on_conectbuton_clicked();
    void on_sentbuton_clicked();
    void processechatbot(QString command);
    void condesed();
    //serveur
    //vital pour le serveur
    void connectto(QString ip, int port);
    void connected();
    void desconnect();
    void socketerror(QAbstractSocket::SocketError error);
    // optionelle
    void sentdatamap(const QMap<QString,QString> sendmap);
    void sentdatamap(const QString type, QString message, QString psedo, QDateTime seconde, QDateTime minute, QDateTime heurs, QDateTime NoJour, QDate jour);
    void sentdatamap(const QString type, QString message, QString psedo);
    void sentdatamap(const QString type, QString message);
    void sentcommende(const QString commende);
    void sentcommende(const QString commende, QString arg);
    void datareceived();
    void processthemessage(QMap<QString,QString> message);
    void processcomand(QMap<QString,QString> commend);
    QString generatedate();
    QString generatedate(QMap<QString, QString> date);
    QString generatemesage(QString message, QString psedo);
    QString generatemesage(QMap<QString, QString> message);
    QString returnpsedo();
    void on_parametrebuton_clicked();
};
#endif // WIDGET_H

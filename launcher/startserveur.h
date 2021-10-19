#ifndef STARTSERVEUR_H
#define STARTSERVEUR_H

#include <QWidget>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>
#include <QTcpSocket>

namespace Ui {
class startserveur;
}

class startserveur : public QWidget
{
    Q_OBJECT

public:
    explicit startserveur(QWidget *parent = nullptr);
    ~startserveur();

private slots:
    void on_wifi_clicked();
    //void starclient();
    //void datareceived();

private:
    Ui::startserveur *ui;
    QTcpSocket *socket;
    quint16 messagesize;
};

#endif // STARTSERVEUR_H

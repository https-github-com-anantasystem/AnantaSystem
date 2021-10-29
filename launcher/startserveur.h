#ifndef STARTSERVEUR_H
#define STARTSERVEUR_H

#include <QWidget>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>
#include <QTcpSocket>
#include <QSettings>
#include <QFile>

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
    void on_pushButton_clicked();

private:
    QSettings* settings;
    Ui::startserveur *ui;
};

#endif // STARTSERVEUR_H

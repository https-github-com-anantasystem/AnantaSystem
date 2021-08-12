#include "connecttoclient.h"
#include "ui_connecttoclient.h"

connecttoclient::connecttoclient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::connecttoclient)
{
    ui->setupUi(this);
    ui->label_idantufiant->setVisible(false);
    ui->port->setVisible(false);
}

connecttoclient::~connecttoclient()
{
    delete ui;
}

void connecttoclient::on_checkBox_toggled(bool checked)
{
    ui->label_idantufiant->setVisible(!checked);
    ui->port->setVisible(!checked);
}

void connecttoclient::on_pushButton_clicked()
{
    QFile file("start.temp");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << ui->ip->text()+"\n";
    out << ui->port->value();
    if(!QDesktopServices::openUrl(QUrl("chat.exe"))){
        QMessageBox::information(this,tr("erreur a louverture du lien"),tr("le lien ne veut pas souvrir le programe chat.exe a du etre modifier ou suprimer reinstaler le tchat"));
    }
    qApp->quit();
}

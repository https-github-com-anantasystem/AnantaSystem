#include "startserveur.h"
#include "ui_startserveur.h"

startserveur::startserveur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startserveur)
{
    ui->setupUi(this);
    ui->port->setVisible(false);
    ui->label_idantufiant->setVisible(false);
    settings = new QSettings("Ananta System","Tchat",this);
    if(!settings->contains("launcher/serveurPosition")){
        settings->setValue("launcher/serveurPosition","serveur.exe");
    }
}

startserveur::~startserveur()
{
    delete ui;
}
void startserveur::on_pushButton_clicked()
{
    QFile file("start.temp");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << ui->ip->text()+"\n";
    out << ui->port->value();
    if(!QDesktopServices::openUrl(QUrl(settings->value("launcher/serveurPosition").toString()))){
        QMessageBox::information(this,tr("erreur a louverture du lien"),tr("le lien ne veut pas souvrir la clef du registre a du etre modifier reinstaler le tchat"));
    }
    qApp->quit();
}


#include "parametre.h"
#include "ui_parametre.h"

parametre::parametre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parametre)
{
    ui->setupUi(this);
    settings = new QSettings("ananta system","tchat 4.1",this);
    if(!settings->contains("settings/SaveMessage")){
        settings->setValue("settings/SaveMessage",true);
    }if(!settings->contains("settings/visualNotification")){
        settings->setValue("settings/visualNotification",true);
    }if(!settings->contains("settings/SoundNotification")){
        settings->setValue("settings/SoundNotification",true);
    }if(!settings->contains("settings/color")){
        settings->setValue("settings/color","white");
    }if(!settings->contains("settings/path")){
        settings->setValue("settings/path",":/sound/notifdefault.wav");
    }if(!settings->contains("settings/transparency")){
        settings->setValue("settings/transparency","0.5");
    }
    ui->checkBox_3->setChecked(settings->value("settings/SaveMessage").toBool());
    ui->checkBox_2->setChecked(settings->value("settings/visualNotification").toBool());
    ui->checkBox->setChecked(settings->value("settings/SoundNotification").toBool());
    ui->comboBox_3->setCurrentText(settings->value("settings/color").toString());
    ui->comboBox->setCurrentText(settings->value("settings/path").toString());
    ui->comboBox_2->setCurrentText(settings->value("settings/langage").toString());
    if(settings->value("settings/transparency").toString()=="0.5"){
        ui->checkboxmodecondensee->setChecked(true);
    }else if(settings->value("settings/transparency").toString()=="1.0"){
        ui->checkboxmodecondensee->setChecked(false);
    }
}

parametre::~parametre()
{
    delete ui;
}
QPalette parametre::starttheme(){
   if(settings->value("settings/color").toString()=="black"){
       ui->comboBox_3->setCurrentIndex(1);
        return darkmode();
   }else if(settings->value("settings/color").toString()=="white"){
       ui->comboBox_3->setCurrentIndex(0);
       return whitemode();
   }else{
       return whitemode();
       QMessageBox::warning(this,tr("erreur de lecture"),tr("il est imposible de lire la couleur par defaut. elle est donc par defaut a blanc"));
       on_comboBox_3_activated(tr("blanc","atention meme chose que dans l'ui la combo box de coulleur"));
   }

}
QPalette parametre::darkmode(){
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    return darkPalette;
}
QPalette parametre::whitemode(){
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(240,240,240));
    darkPalette.setColor(QPalette::WindowText, QColor(0,0,0));
    darkPalette.setColor(QPalette::Base, QColor(255,255,255));
    darkPalette.setColor(QPalette::AlternateBase, QColor(240,240,240));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::black);
    darkPalette.setColor(QPalette::ToolTipText, Qt::black);
    darkPalette.setColor(QPalette::Text, Qt::black);
    darkPalette.setColor(QPalette::Button, QColor(240,240,240));
    darkPalette.setColor(QPalette::ButtonText, Qt::black);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(59, 62, 178));
    darkPalette.setColor(QPalette::Highlight, QColor(0, 0, 255));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    return darkPalette;
}
void parametre::on_checkBox_3_toggled(bool checked)
{
        settings->setValue("settings/SaveMessage",checked);
}
void parametre::on_checkBox_2_toggled(bool checked)
{
        settings->setValue("settings/visualNotification",checked);
}
void parametre::on_checkBox_toggled(bool checked)
{
    settings->setValue("settings/SoundNotification",checked);
}
void parametre::on_comboBox_2_activated(const QString &arg1)
{
    settings->setValue("settings/langage",arg1);
    QMessageBox::information(this, tr("traduction"), tr("pour rendre effective ce changement il faut recharger l'aplication", "doit etre en anglais dans l'aplication francaise et anglaise dans l'app anglaise et toute les autre langue en anglais"));
}
void parametre::on_comboBox_3_activated(const QString &arg1)
{
    if(arg1==tr("blanc","atention meme chose que dans l'ui la combo box de coulleur")){
        whitemode();
    }else if(arg1==tr("noir","atention meme chose que dans l'ui la combo box de coulleur")){
        darkmode();
    }else{
        QMessageBox::warning(this,tr("couleur non trouver"),tr("atention cette couleur n'existe pas dans les version actuelle du tchat"));
        return;
    }
    settings->setValue("settings/color",arg1);
}
void parametre::on_comboBox_activated(const QString &arg1)
{
    {
        if(arg1==tr("selectioner une musique","atention meme chose que dans l'ui la combo box de selection de musique")){
            //path = reponse of message box
            settings->setValue("settings/path",QFileDialog::getOpenFileName(this, tr("charger une musique"), nullptr , tr("fichier audio (*.MP3 *.WAV)")));
            if(settings->value("settings/path")==""){
                settings->setValue("settings/path",":/sound/notifdefault.wav");
                QMessageBox::warning(this,tr("erreur de chemin"),tr("atention le chemin de fichier et inutilisablepassage en musique par default"));

            }
        }else if(arg1==tr("blup blup","atention meme chose que dans l'ui la combo box de selection de musique")){
            settings->setValue("sound/path",":/sound/Sonnerie_Ananta.wav");
        }else if(arg1==tr("son par default","atention meme chose que dans l'ui la combo box de selection de musique")){
            settings->setValue("sound/path",":/sound/notifdefault.wav");
        }
    }
}
void parametre::on_deletbuton_clicked()
{
    int reponse = QMessageBox::warning(this,tr("atention supression"),tr("atention le fichier va etre definitivement suprimer il ne sera pas deplacer dans la corbeille voulez vous continuer"), QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        if (remove("chat.ants")){
            QMessageBox::information(this,tr("supression resi"),tr("la spression a été un succès)"));
        }else{
             QMessageBox::information(this,tr("supression loupé"),tr("la spression a été un echeque pour une raison indefini"));
        }
    }
}
void parametre::on_site_clicked()
{
    if(!QDesktopServices::openUrl(QUrl("anantasystem.com"))){
        QMessageBox::information(this,tr("erreur a louverture du lien"),tr("le lien ne veut pas souvrir le probleme vien de votre navigateur par default taper anantasystem.com dans votre navigateur et faite nous un raport de bug sur le discord"));
    }
}
void parametre::on_discord_clicked()
{
    if(!QDesktopServices::openUrl(QUrl("anantasystem.com/discord.html"))){
        QMessageBox::information(this,tr("erreur a louverture du lien"),tr("le lien ne veut pas souvrir le probleme vien de votre navigateur par default taper anantasystem.com/discord.html dans votre navigateur et faite nous un raport de bug sur le discord"));
    }
}
void parametre::on_tweter_clicked()
{
    if(!QDesktopServices::openUrl(QUrl("anantasystem.com/twitter.html"))){
        QMessageBox::information(this,tr("erreur a louverture du lien"),tr("le lien ne veut pas souvrir le probleme vien de votre navigateur par default taper anantasystem.com/twitter.html dans votre navigateur et faite nous un raport de bug sur le discord"));
    }
}

void parametre::on_checkboxmodecondensee_toggled(bool checked)
{
    if(checked){
        settings->setValue("settings/transparency","0.5");
    }else if (!checked) {
        settings->setValue("settings/transparency","1.0");
    }else{
        QMessageBox::warning(this,tr("erreur checkbox"),tr("cette boite de dialogue contien normalenet que deux etat la elle en a troisfaite nous un raport dans le discord"));
    }
}

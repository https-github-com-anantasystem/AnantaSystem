#include "parametre.h"
#include "ui_parametre.h"

parametre::parametre(QList<QMap<QString,QString>> &ref,QWidget *parent) :
   QDialog(parent),
   remouveFiles(ref,nullptr),
   ui(new Ui::parametre)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    remouveFile remouveFiles(ref,nullptr);
    ui->setupUi(this);
    settings = new QSettings("Ananta System","Tchat",this);
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
       QMessageBox::warning(this,tr("Erreur de lecture"),tr("Il est impossible de lire la couleur par défaut. Elle est donc définit sur blanc"));
       on_comboBox_3_activated(tr("Blanc","Attention même chose que dans l'ui la combo box de couleur"));
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
    if(arg1==tr("Blanc","Attention même chose que dans l'ui la combo box de couleur")){
        whitemode();
    }else if(arg1==tr("Noir","Attention même chose que dans l'ui la combo box de couleur")){
        darkmode();
    }else{
        QMessageBox::warning(this,tr("Couleur non trouvée"),tr("Attention cette couleur n'existe pas dans la version actuelle du tchat"));
        return;
    }
    settings->setValue("settings/color",arg1);
}
void parametre::on_comboBox_activated(const QString &arg1)
{
    {
        if(arg1==tr("Personnalisée","Attention même chose que dans l'ui la combo box de sélection de musique")){
            //path = reponse of message box
            settings->setValue("settings/path",QFileDialog::getOpenFileName(this, tr("Charger une musique"), nullptr , tr("fichier audio (*.MP3 *.WAV)")));
            if(settings->value("settings/path")==""){
                settings->setValue("settings/path",":/sound/notifdefault.wav");
                QMessageBox::warning(this,tr("Erreur de chemin"),tr("Attention le chemin de fichier et inutilisable, passage en musique par défaut"));

            }
        }else if(arg1==tr("Blup Blup","Attention même chose que dans l'ui la combo box de sélection de musique")){
            settings->setValue("sound/path",":/sound/Sonnerie_Ananta.wav");
        }else if(arg1==tr("Sonnerie par défaut","Attention même chose que dans l'ui la combo box de sélection de musique")){
            settings->setValue("sound/path",":/sound/notifdefault.wav");
        }
    }
}
void parametre::on_deletbuton_clicked()
{
    remouveFiles.show();
    /*int reponse = QMessageBox::warning(this,tr("atention supression"),tr("atention le fichier va etre definitivement suprimer il ne sera pas deplacer dans la corbeille voulez vous continuer"), QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        if (remove("chat.ants")){
            QMessageBox::information(this,tr("Supression réussi"),tr("La supression a été un effectuée)"));
        }else{
             QMessageBox::information(this,tr("Supression raté"),tr("La supression a échouée pour une raison indéfini"));
        }
    }*/
}
void parametre::on_site_clicked()
{
    if(!QDesktopServices::openUrl(QUrl("https://anantasystem.com"))){
        QMessageBox::information(this,tr("Erreur a l'ouverture du lien"),tr("Le lien ne veut pas s'ouvrir le probleme vient de votre navigateur.Veuillez aller sur anantasystem.com et faites-nous un rapport de bug sur le Discord"));
    }
}
void parametre::on_discord_clicked()
{
    if(!QDesktopServices::openUrl(QUrl("https://anantasystem.com/discord.html"))){
        QMessageBox::information(this,tr("Erreur a l'ouverture du lien"),tr("Le lien ne veut pas s'ouvrir le probleme vient de votre navigateur. Veuillez aller sur anantasystem.com et faites-nous un rapport de bug sur le Discord"));
    }
}
void parametre::on_tweter_clicked()
{
    if(!QDesktopServices::openUrl(QUrl("https://anantasystem.com/twitter.html"))){
        QMessageBox::information(this,tr("Erreur a l'ouverture du lien"),tr("Le lien ne veut pas s'ouvrir le probleme vient de votre navigateur. Veuillez aller sur anantasystem.com et faites-nous un rapport de bug sur le Discord"));
    }
}

void parametre::on_checkboxmodecondensee_toggled(bool checked)
{
    if(checked){
        settings->setValue("settings/transparency","0.5");
    }else if (!checked) {
        settings->setValue("settings/transparency","1.0");
    }else{
        QMessageBox::warning(this,tr("Erreur checkbox"),tr("Cette boite de dialogue est dans un troisème état inexistant. Veuillez nous faire un rapport de bug dans le Discord"));
    }
}

void parametre::on_pushButton_3_clicked()
{
    succes = new sucees(this);
    succes->show();
}


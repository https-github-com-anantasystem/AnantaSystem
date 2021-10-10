#include "parametre.h"
#include "ui_parametre.h"

parametre::parametre(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::parametre)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    colors = new QSettings("color.ini",QSettings::IniFormat);
    colors->setValue("test","test.qss");
    succes = new sucees(this);
    settings = new QSettings("ananta system","tchat 4.1",this);
    ui->checkBox_2->setChecked(settings->value("settings/visualNotification").toBool());
    ui->checkBox->setChecked(settings->value("settings/SoundNotification").toBool());
    ui->setcollor->setCurrentText(settings->value("settings/color").toString());
    ui->comboBox->setCurrentText(settings->value("settings/path").toString());
    ui->comboBox_2->setCurrentText(settings->value("settings/langage").toString());
    if(settings->value("settings/transparency").toString()=="0.5"){
        ui->checkboxmodecondensee->setChecked(true);
    }else if(settings->value("settings/transparency").toString()=="1.0"){
        ui->checkboxmodecondensee->setChecked(false);
    }
               //this->setStyleSheet("/*-----QWidget-----*/QWidget{	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0.100962 rgba(34, 166, 178, 255),stop:0.543269 rgba(132, 213, 51, 255),stop:1 rgba(208, 255, 163, 255));	color: #ffffff;	font-weight: bold;	border-color: #051a39;	selection-background-color: #3b7e48;}/*-----QLabel-----*/QLabel{	background-color: transparent;	color: #ffffff;}QLabel::disabled{	background-color: transparent;	color: #656565;}/*-----QMenuBar-----*/QMenuBar{	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0.100962 rgba(34, 166, 178, 255),stop:1 rgba(24, 123, 132, 255));	color: #ffffff;	border-color: #051a39;}QMenuBar::disabled{	background-color: #404040;	color: #656565;	border-color: #051a39;}QMenuBar::item{    background-color: transparent;}QMenuBar::item:selected{    background-color: #5ab8a0;    border: 1px solid #41cd52;}QMenuBar::item:pressed{    background-color: #3e7f6e;    border: 1px solid #5ab8a0;    margin-bottom: -1px;    padding-bottom: 1px;}/*-----QMenu-----*/QMenu{    background-color: #1f2b2b;    border: 1px solid;    color: #ffffff;}QMenu::separator{    height: 1px;    background-color: #22af00;    color: #ffffff;    padding-left: 4px;    margin-left: 10px;    margin-right: 5px;}QMenu::item{    min-width : 150px;    padding: 3px 20px 3px 20px;}QMenu::item:selected{    background-color: #22a6b2;    color: #ffffff;}QMenu::item:disabled{    color: #262626;}/*-----QToolTip-----*/QToolTip{	border : 1px solid #000000;	background-color: #26264f;	color: #ffffff;	border-color: #051a39;}/*-----QPushButton-----*/QPushButton{	background-color: #20afe7;	color: #ffffff;	border-style: solid;	border-width: 1px;	border-radius: 11px;	border-color: #2082ff;	padding: 5px;}QPushButton::disabled{	background-color: #404040;	color: #656565;	border-color: #051a39;}QPushButton::hover{	background-color: #33bdff;	color: #ffffff;	border-style: solid;	border-width: 1px;	border-radius: 11px;	border-color: #2082ff;	padding: 5px;}QPushButton::pressed{	background-color: #2082ff;	color: #ffffff;	border-style: solid;	border-width: 1px;	border-radius: 11px;	border-color: #2082ff;	padding: 5px;}/*-----QToolButton-----*/QToolButton{	background-color: #20afe7;	color: #ffffff;	border-style: solid;	border-width: 1px;	border-radius: 11px;	border-color: #2082ff;	padding: 5px;}QToolButton::disabled{	background-color: #404040;	color: #656565;	border-color: #051a39;}QToolButton::hover{	background-color: #33bdff;	color: #ffffff;	border-style: solid;	border-width: 1px;	border-radius: 11px;	border-color: #2082ff;	padding: 5px;}QToolButton::pressed{	background-color: #2082ff;	color: #ffffff;	border-style: solid;	border-width: 1px;	border-radius: 11px;	border-color: #2082ff;	padding: 5px;}/*-----QComboBox-----*/QComboBox{    background-color: #a9a9aa;    border: 1px solid;    padding-left: 6px;    color: #000;    height: 20px;}QComboBox::disabled{	background-color: #404040;	color: #656565;	border-color: #051a39;}QComboBox:hover{    background-color: #f6f6f6;}QComboBox:on{    background-color: #f8f6f0;}QComboBox QAbstractItemView{    background-color: #383838;    color: #ffffff;    border: 1px solid black;    selection-background-color: #488f44;    selection-color: #ffffff;    outline: 0;}QComboBox::drop-down{    subcontrol-origin: padding;    subcontrol-position: top right;    width: 15px;}QComboBox::down-arrow{	background-color: #383838;	    image: url(://arrow-down.png) 16px 16px;    width: 18px;    height: 18px;	border-left: 1px solid black;}/*-----QSpinBox & QDoubleSpinBox & QDateTimeEdit-----*/QSpinBox, QDoubleSpinBox,QDateTimeEdit{	background-color: #f6f6f6;	color: #000;	border: 1px solid #a9a9aa;	padding : 2px;}QSpinBox::disabled, QDoubleSpinBox::disabled,QDateTimeEdit::disabled{	background-color: #404040;	color: #656565;	border-color: #051a39;}QSpinBox:hover, QDoubleSpinBox::hover,QDateTimeEdit::hover{    background-color: #a9a9aa;    border: 1px solid #a9a9aa;    color:  #000;    padding: 2px}QSpinBox::up-button, QSpinBox::down-button,QDoubleSpinBox::up-button, QDoubleSpinBox::down-button,QDateTimeEdit::up-button, QDateTimeEdit::down-button{    background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0.100962 rgba(34, 166, 178, 255),stop:0.543269 rgba(132, 213, 51, 255),stop:1 rgba(208, 255, 163, 255));}QSpinBox::disabled, QDoubleSpinBox::disabled,QDateTimeEdit::disabled{	background-color: #404040;	color: #656565;	border-color: #051a39;}QSpinBox::up-button:hover, QSpinBox::down-button:hover,QDoubleSpinBox::up-button:hover, QDoubleSpinBox::down-button:hover,QDateTimeEdit::up-button:hover, QDateTimeEdit::down-button:hover{    background-color: #92dd48;    border: 1px solid #92dd48;}QSpinBox::up-button:disabled, QSpinBox::down-button:disabled,QDoubleSpinBox::up-button:disabled, QDoubleSpinBox::down-button:disabled,QDateTimeEdit::up-button:disabled, QDateTimeEdit::down-button:disabled{	background-color: #404040;	color: #656565;	border-color: #051a39;}QSpinBox::up-button:pressed, QSpinBox::down-button:pressed,QDoubleSpinBox::up-button:pressed, QDoubleSpinBox::down-button::pressed,QDateTimeEdit::up-button:pressed, QDateTimeEdit::down-button::pressed{    background-color: #57a951;    border: 1px solid #57a951;}QSpinBox::down-arrow,QDoubleSpinBox::down-arrow,QDateTimeEdit::down-arrow{    image: url(://arrow-down.png);    width: 7px;}QSpinBox::up-arrow,QDoubleSpinBox::up-arrow,QDateTimeEdit::up-arrow{    image: url(://arrow-up.png);    width: 7px;}/*-----QLineEdit-----*/QLineEdit{	background-color: #f6f6f6;	color: #000;	border-width: 1px;	border-radius: 0px;	border-color: #051a39;	padding: 2px;}QLineEdit::hover{	background-color: #a9a9aa;	color: #000;}QLineEdit::disabled{	background-color: #404040;	color: #656565;	border-width: 1px;	border-radius: 3px;	border-color: #051a39;	padding: 2px;}/*-----QTextEdit-----*/QTextEdit{	background-color: #ffffff;	color: #010201;	border-color: #051a39;}QTextEdit::disabled{	background-color: #404040;	color: #656565;	border-color: #051a39;}/*-----QGroupBox-----*/QGroupBox {	background-color: #1f2b2b;    border: 1px inset #000;    margin-top: 22px;	margin-left: 1px;}QGroupBox::title  {    background-color: #1f2b2b;    color: #ffffff;    subcontrol-origin: margin;    subcontrol-position: top left;	margin-left: 1px;    padding: 5px;}QGroupBox::title::disabled{	background-color: #404040;	color: #656565;}/*-----QCheckBox-----*/QCheckBox{    background-color: transparent;}QCheckBox::indicator{    color: #b1b1b1;    background-color: #1f2b2b;    border: 1px solid #2aaaa8;    width: 12px;    height: 12px;}QCheckBox::indicator:checked{    image:url(://checkbox.png);	background-color: #1f2b2b;    border: 1px solid #2aaaa8;}QCheckBox::indicator:unchecked:hover{    border: 1px solid #2aaaa8;}QCheckBox::disabled{	color: #656565;}QCheckBox::indicator:disabled{	background-color: #656565;	color: #656565;    border: 1px solid #656565;}/*-----QRadioButton-----*/QRadioButton{    background-color: transparent;}QRadioButton::indicator::unchecked{ 	border: 1px inset gray; 	border-radius: 5px; 	background-color:  #a9a9aa;	width: 9px; 	height: 9px; }QRadioButton::indicator::unchecked:hover{ 	border: 1px inset #2aaaa8; 	border-radius: 5px; 	background-color: gray;	width: 9px; 	height: 9px; }QRadioButton::indicator::checked{ 	border: 1px solid #607cff; 	border-radius: 5px; 	background-color: #58fa53; 	width: 9px; 	height: 9px; }QRadioButton::disabled{	color: #656565;}QRadioButton::indicator:disabled{	background-color: #656565;	color: #656565;    border: 2px solid #656565;}/*-----QTableView & QTableWidget-----*/QTableView{    background-color: #242526;    border: 1px solid #32414B;    color: #F0F0F0;    gridline-color: #353635;    outline : 0;}QTableView::item:hover{    background-color: #24602b;    color: #F0F0F0;}QTableView::item:selected{    background-color: #60c461;    border: 2px solid #60c461;    color: #F0F0F0;}QTableCornerButton::section{    background-color: #505050;    color: white;}QHeaderView{    background-color: #505050;    color: white;    border-radius: 0px;    text-align: left;}QHeaderView::section{    background-color: #505050;    color: white;    border-radius: 0px;    text-align: left;	padding: 3px;}QHeaderView::section:checked{    color: #000000;    background-color: #60c461;}QHeaderView::section::vertical::first,QHeaderView::section::vertical::only-one{    border-top: 1px solid #353635;}QHeaderView::section::vertical{    border-top: 1px solid #353635;}QHeaderView::section::horizontal::first,QHeaderView::section::horizontal::only-one{    border-left: 1px solid #353635;}QHeaderView::section::horizontal{    border-left: 1px solid #353635;}/*-----QTabWidget-----*/QTabBar::tab{	background-color: #1f2b2b;	color: #ffffff;	border-style: solid;	border-width: 1px;	border-color: #051a39;	padding: 5px;}QTabBar::tab:disabled{	background-color: #656565;	color: #656565;}QTabWidget::pane{	background-color: transparent;    border: 1px solid;    border-color: #1f2b2b;}QTabBar::tab:selected{    background-color: #1f2b2b;	color: #ffffff;	border-style: solid;	border-width: 0px;	border-color: #051a39;	padding: 5px;}QTabBar::tab:selected:disabled{	background-color: #404040;	color: #656565;}QTabBar::tab:!selected {    background-color: #262626;}QTabBar::tab:!selected:hover {    background-color: #1f2b2b;}QTabBar::tab:top:!selected {    margin-top: 3px;}QTabBar::tab:bottom:!selected {    margin-bottom: 3px;}QTabBar::tab:top, QTabBar::tab:bottom {    min-width: 8ex;    margin-right: -1px;    padding: 5px 10px 5px 10px;}QTabBar::tab:top:selected {    border-bottom-color: none;}QTabBar::tab:bottom:selected {    border-top-color: none;}QTabBar::tab:top:last, QTabBar::tab:bottom:last,QTabBar::tab:top:only-one, QTabBar::tab:bottom:only-one {    margin-right: 0;}QTabBar::tab:left:!selected {    margin-right: 3px;}QTabBar::tab:right:!selected{    margin-left: 3px;}QTabBar::tab:left, QTabBar::tab:right {    min-height: 8ex;    margin-bottom: -1px;    padding: 10px 5px 10px 5px;}QTabBar::tab:left:selected {    border-left-color: none;}QTabBar::tab:right:selected {    border-right-color: none;}QTabBar::tab:left:last, QTabBar::tab:right:last,QTabBar::tab:left:only-one, QTabBar::tab:right:only-one {    margin-bottom: 0;}/*-----QSlider-----*/QSlider {	background-color: transparent;}QSlider::groove:horizontal {	background-color: transparent;	height: 5px;}QSlider::sub-page:horizontal {	background-color: #41cd52;}QSlider::add-page:horizontal {	background-color: #a9a9aa;}QSlider::handle:horizontal {	background-color: #41cd52;	width: 14px;	margin-top: -6px;	margin-bottom: -6px;	border-radius: 3px;}QSlider::handle:horizontal:hover {	background-color: #22af00;	border-radius: 3px;}QSlider::sub-page:horizontal:disabled {	background-color: #bbb;	border-color: #999;}QSlider::add-page:horizontal:disabled {	background-color: #eee;	border-color: #999;}QSlider::handle:horizontal:disabled {	background-color: #eee;	border: 1px solid #aaa;	border-radius: 3px;}QSlider::groove:vertical {	background-color: transparent;	width: 5px;}QSlider::sub-page:vertical {	background-color: #41cd52;}QSlider::add-page:vertical {	background-color: #a9a9aa;}QSlider::handle:vertical {	background-color: #41cd52;	height: 14px;	margin-left: -6px;	margin-right: -6px;	border-radius: 3px;}QSlider::handle:vertical:hover {	background-color: #22af00;	border-radius: 3px;}QSlider::sub-page:vertical:disabled {	background-color: #bbb;	border-color: #999;}QSlider::add-page:vertical:disabled {	background-color: #eee;	border-color: #999;}QSlider::handle:vertical:disabled {	background-color: #eee;	border: 1px solid #aaa;	border-radius: 3px;}/*-----QDial-----*/QDial{	background-color: #58ae53;}QDial::disabled{	background-color: #404040;}/*-----QScrollBar-----*/QScrollBar:horizontal{    border: 1px solid #222222;    background-color: #3d3d3d;    height: 15px;    margin: 0px 16px 0 16px;}QScrollBar::handle:horizontal{    background-color: #41cd52;    min-height: 20px;}QScrollBar::add-line:horizontal{    border: 1px solid #1b1b19;    background-color: #41cd52;    width: 14px;    subcontrol-position: right;    subcontrol-origin: margin;}QScrollBar::sub-line:horizontal{    border: 1px solid #1b1b19;    background-color: #41cd52;    width: 14px;    subcontrol-position: left;    subcontrol-origin: margin;}QScrollBar::right-arrow:horizontal{    image: url(://arrow-right.png);    width: 6px;    height: 6px;}QScrollBar::left-arrow:horizontal{    image: url(://arrow-left.png);    width: 6px;    height: 6px;}QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal{    background: none;}QScrollBar:vertical{    background-color: #3d3d3d;    width: 13px;    margin: 16px 0 16px 0;    border: 1px solid #222222;}QScrollBar::handle:vertical{    background-color: #41cd52;    min-height: 20px;}QScrollBar::add-line:vertical{    border: 1px solid #1b1b19;    background-color: #41cd52;    height: 14px;    subcontrol-position: bottom;    subcontrol-origin: margin;}QScrollBar::sub-line:vertical{    border: 1px solid #41cd52;    background-color: #41cd52;    height: 14px;    subcontrol-position: top;    subcontrol-origin: margin;}QScrollBar::up-arrow:vertical{    image: url(://arrow-up.png);    width: 6px;    height: 6px;}QScrollBar::down-arrow:vertical{    image: url(://arrow-down.png);    width: 6px;    height: 6px;}QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{    background: none;}/*-----QProgressBar-----*/QProgressBar{	background-color: #a9a9aa;	color: #000;	border: 1px solid #000;	text-align: center;}QProgressBar::chunk {	background-color: #36b9b1;	color: #fff;}QProgressBar::chunk:disabled {	background-color: #656565;	border: 1px solid #aaa;	color: #656565;}/*-----QStatusBar-----*/QStatusBar{	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0.100962 rgba(98, 197, 95, 255),stop:1 rgba(80, 158, 75, 255));	color: #ffffff;	border-color: #051a39;}");
    starttheme();
}
parametre::~parametre()
{
    delete ui;
    delete colors;
    delete succes;
}
QPalette parametre::starttheme(){
   if(settings->value("settings/color").toString()=="black"){
       ui->setcollor->setCurrentIndex(1);
        return darkmode();
   }else if(settings->value("settings/color").toString()=="white"){
       ui->setcollor->setCurrentIndex(0);
       return whitemode();
   }else{
       return whitemode();
       QMessageBox::warning(this,tr("erreur de lecture"),tr("il est imposible de lire la couleur par defaut. elle est donc par defaut a blanc"));
       on_setcollor_activated(tr("blanc","atention meme chose que dans l'ui la combo box de coulleur"));
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
void parametre::on_setcollor_activated(const QString &arg1)
{
    settings->setValue("settings/color",arg1);
    starttheme();
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

void parametre::on_pushButton_3_clicked()
{
    succes->show();
}
void parametre::on_pushButton_4_clicked()
{
    moreinformations = new moreinformation(this);
    moreinformations->show();
}


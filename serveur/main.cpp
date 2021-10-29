#include "widget.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    QString texte;
    QFile fichier("languages/language.ants");
    if(fichier.open(QIODevice::ReadOnly)){
       texte = fichier.readAll();
       fichier.close();
       translator.load("languages/server_"+texte+".qm");
    }else{
       translator.load("languages/server_fr_FR.qm");
   }
    a.installTranslator(&translator);
    Widget w;
    w.show();
    return a.exec();
}

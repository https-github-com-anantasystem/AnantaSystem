#include <QCoreApplication>
#include <iostream>
#include "server.h"
void pinup(QString message){
    std::cout <<message.toStdString() << std::endl;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    pinup("starting...");
    server();
    return a.exec();
}


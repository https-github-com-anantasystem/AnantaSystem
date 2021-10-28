QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    succees.cpp \
    utilisateur.cpp \
    widget.cpp \
    parametre.cpp \
    moreinformation.cpp

HEADERS += \
    succees.h \
    utilisateur.h \
    widget.h \
    parametre.h \
    moreinformation.h

FORMS += \
    succees.ui \
    widget.ui \
    parametre.ui \
    moreinformation.ui

TRANSLATIONS += \
    serveur_fr_FR.ts
    serveur_an_AN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

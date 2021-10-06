QT       += core gui network multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    moreinformation.cpp \
    parametre.cpp \
    succees.cpp \
    widget.cpp

HEADERS += \
    moreinformation.h \
    parametre.h \
    succees.h \
    widget.h

FORMS += \
    moreinformation.ui \
    parametre.ui \
    succees.ui \
    widget.ui

TRANSLATIONS += \
    chat_fr_FR.ts
    chat_An_AN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    chat_An_AN.ts
    chat_fr_FR.ts

RESOURCES += \
    resources.qrc

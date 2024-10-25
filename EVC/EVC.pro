QT       += core gui serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    displaywindow.cpp \
    history.cpp \
    information.cpp \
    listcard.cpp \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    nfcworker.cpp \
    notion.cpp

HEADERS += \
    displaywindow.h \
    history.h \
    information.h \
    listcard.h \
    mainwindow.h \
    menuwindow.h \
    nfcworker.h \
    notion.h

FORMS += \
    displaywindow.ui \
    history.ui \
    information.ui \
    listcard.ui \
    mainwindow.ui \
    menuwindow.ui \
    notion.ui
INCLUDEPATH += /usr/local/include/nfc
LIBS += -lnfc
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

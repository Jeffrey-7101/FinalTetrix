QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Pieza.cpp \
        dificultwindow.cpp \
        main.cpp \
        qtetrixboard.cpp \
        qtetrixwindow.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Forma.h \
    Pieza.h \
    dificultwindow.h \
    qtetrixboard.h \
    qtetrixwindow.h

QT += widgets

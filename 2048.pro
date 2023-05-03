QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LogWidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    LogWidget.h \
    mainwindow.h

FORMS += \
    LogWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    resources/axqsx-7wyta-001.ico \
    resources/level1.png \
    resources/level128.png \
    resources/level16.png \
    resources/level2.png \
    resources/level256.png \
    resources/level32.png \
    resources/level4.png \
    resources/level64.png \
    resources/level8.png \
    resources/loading.png \
    resources/login.png

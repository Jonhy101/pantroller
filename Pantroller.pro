QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gui/devices/pic18f4550.cpp \
    gui/devicewidget.cpp \
    gui/mainmenugenerator.cpp \
    gui/widgetsfactory.cpp \
    logic/devices.cpp \
    logic/helpbutton.cpp \
    main.cpp\
    gui/mainwindow.cpp

HEADERS += \
    gui/devices/pic18f4550.h \
    gui/devicewidget.h \
    gui/guiColors.h \
    gui/widgetsfactory.h \
    gui/mainmenugenerator.h\
    gui/mainwindow.h \
    logic/devices.h \
    logic/helpbutton.h

FORMS += \
    gui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/my_resources.qrc

INCLUDEPATH += $$PWD/gui
INCLUDEPATH += $$PWD/logic

DISTFILES += \
    resources/styles/styles.qss

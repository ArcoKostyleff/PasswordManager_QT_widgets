QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LoginForm.cpp \
    Users.cpp \
    addrowform.cpp \
    main.cpp \
    mainwindow.cpp \
    registerform.cpp

HEADERS += \
    LoginForm.h \
    Users.h \
    addrowform.h \
    mainwindow.h \
    registerform.h

FORMS += \
    LoginForm.ui \
    addrowform.ui \
    mainwindow.ui \
    registerform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    usersList.xml

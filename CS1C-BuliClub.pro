QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcustomer.cpp \
    additme.cpp \
    adminpage.cpp \
    dbmanager.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    memberpurchase.cpp \
    membershipchange.cpp \
    storemanager.cpp

HEADERS += \
    addcustomer.h \
    additme.h \
    adminpage.h \
    dbmanager.h \
    login.h \
    mainwindow.h \
    memberpurchase.h \
    membershipchange.h \
    storemanager.h

FORMS += \
    addcustomer.ui \
    additme.ui \
    adminpage.ui \
    login.ui \
    mainwindow.ui \
    memberpurchase.ui \
    membershipchange.ui \
    storemanager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

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
    managerdailyreport.cpp \
    memberpurchase.cpp \
    membershipchange.cpp \
    rebatemember.cpp \
    salesreport.cpp \
    storemanager.cpp \
    totalpurchase.cpp \
    totalrevenue.cpp

HEADERS += \
    addcustomer.h \
    additme.h \
    adminpage.h \
    dbmanager.h \
    login.h \
    mainwindow.h \
    managerdailyreport.h \
    memberpurchase.h \
    membershipchange.h \
    rebatemember.h \
    salesreport.h \
    storemanager.h \
    totalpurchase.h \
    totalrevenue.h

FORMS += \
    addcustomer.ui \
    additme.ui \
    adminpage.ui \
    login.ui \
    mainwindow.ui \
    managerdailyreport.ui \
    memberpurchase.ui \
    membershipchange.ui \
    rebatemember.ui \
    salesreport.ui \
    storemanager.ui \
    totalpurchase.ui \
    totalrevenue.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

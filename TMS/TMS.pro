QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fileload.cpp \
    filesave.cpp \
    main.cpp \
    loginwindow.cpp \
    programwindow.cpp \
    projaboutwindow.cpp \
    project.cpp \
    projectcreatewindow.cpp \
    projecteditwindow.cpp \
    registrationwindow.cpp \
    statuschangewindow.cpp \
    task.cpp \
    taskprogramwindow.cpp \
    user.cpp

HEADERS += \
    fileload.h \
    filesave.h \
    loginwindow.h \
    programwindow.h \
    projaboutwindow.h \
    project.h \
    projectcreatewindow.h \
    projecteditwindow.h \
    registrationwindow.h \
    statuschangewindow.h \
    task.h \
    taskprogramwindow.h \
    user.h

FORMS += \
    loginwindow.ui \
    programwindow.ui \
    projaboutwindow.ui \
    projectcreatewindow.ui \
    projecteditwindow.ui \
    registrationwindow.ui \
    statuschangewindow.ui \
    taskprogramwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

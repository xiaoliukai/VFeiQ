#-------------------------------------------------
#
# Project created by QtCreator 2014-07-07T15:12:15
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VFeiQ
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ChatForm.cpp \
    model/ChatMessage.cpp \
    model/FriendSet.cpp \
    service/ChatService.cpp \
    service/BroadcastService.cpp \
    model/User.cpp \
    service/UdpService.cpp \
    service/UserService.cpp \
    model/ChatRcord.cpp

HEADERS  += MainWindow.h \
    ChatForm.h \
    model/ChatMessage.h \
    model/FriendSet.h \
    service/ChatService.h \
    service/BroadcastService.h \
    model/User.h \
    service/UdpService.h \
    service/UserService.h \
    model/ChatRcord.h

FORMS    += MainWindow.ui \
    ChatForm.ui

RESOURCES += \
    skins.qrc \
    images.qrc
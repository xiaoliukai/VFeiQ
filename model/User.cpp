#include "User.h"

User::User(QObject *parent) :
    QObject(parent)
{
    this->uuid = QUuid::createUuid();
}

User::User(const QHostAddress &ip, const QString &name, QObject *parent) :
    QObject(parent),
    ip(ip),
    name(name)
{
    this->uuid = QUuid::createUuid();
}

User::User(const QString &userStr, QObject *parent) :
    QObject(parent)
{
    if(userStr.startsWith('{') && userStr.endsWith('}')) {
        QString content = userStr.mid(1, userStr.size()-2);
        QStringList cList = content.split(',');
        if(cList.size() != 7) {
            emit parseError("Incomplete structure");
            return ;
        }

        uuid = QUuid(cList[0]);
        ip = QHostAddress(cList[1]);
        name = cList[2];
        icon = QIcon(cList[3]);
        logTime = QDateTime::fromString(cList[4]);
        info = cList[5];
        status = (Status)cList[6].toInt();
    } else {
        emit parseError("Incomplete message");
    }

}

QString User::toString(){
    QString userStr = QString("{%1,%2,%3,%4,%5,%6,%7}")
            .arg(uuid.toString())
            .arg(ip.toString())
            .arg(name)
            .arg(icon.name())
            .arg(logTime.toString())
            .arg(info)
            .arg((int)status);
    return userStr;
}

User::User(const User &user){
    uuid = user.uuid;
    ip = user.ip;
    name = user.name;
    icon = user.icon;
    logTime = user.logTime;
    info = user.info;
    status = user.status;
}

User &User::operator=(const User &user)
{
    uuid = user.uuid;
    ip = user.ip;
    name = user.name;
    icon = user.icon;
    logTime = user.logTime;
    info = user.info;
    status = user.status;
    return *this;
}

QUuid User::getUuid(){
    return this->uuid;
}

QHostAddress User::getIp(){
    return this->ip;
}

QString User::getName(){
    return this->name;
}

QIcon User::getIcon(){
    return this->icon;
}

QDateTime User::getLogTime(){
    return this->logTime;
}

QString User::getInfo(){
    return this->info;
}

User::Status User::getStatus(){
    return this->status;
}

void User::setUuid(const QUuid &uuid){
    this->uuid = uuid;
}

void User::setIp(const QHostAddress &ip){
    this->ip = ip;
}

void User::setName(const QString &name){
    this->name = name;
}

void User::setIcon(const QIcon &icon){
    this->icon = icon;
}

void User::setLogTime(const QDateTime &logTime){
    this->logTime = logTime;
}

void User::setInfo(const QString &info){
    this->info = info;
}

void User::setStatus(Status status){
    this->status = status;
}
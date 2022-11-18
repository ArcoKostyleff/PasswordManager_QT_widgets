#ifndef USERS_H
#define USERS_H

#include <QMap>
#include <QFile>
#include <QDebug>
#include <QXmlStreamReader>
class Users
{
public:
    Users();
    QMap<QString, QString> GetUsersList() ;

};

#endif // USERS_H


#include "Users.h"

Users::Users()
{

}

QMap<QString, QString> Users::GetUsersList()
{
//    QMap<QString, QString> usersMap;
//    QFile* file = new QFile("usersList.xml");
//     if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
//     {
//         qDebug()<<"Error Opening usersList.xml";
//         return usersMap;
//     }
//     QXmlStreamReader xml(file);
//     while (!xml.atEnd() && !xml.hasError())
//     {
//         QXmlStreamReader::TokenType token = xml.readNext();
//         if (token == QXmlStreamReader::StartDocument)
//             continue;
//         if (token == QXmlStreamReader::StartElement)
//         {
//             if (xml.name() == QString("etaps"))
//                 continue;
//             if (xml.name() == QString("etap"))

//         }
//     }
}

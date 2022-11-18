#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "ui_LoginForm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginForm; }
QT_END_NAMESPACE

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    LoginForm(QWidget *parent = nullptr);
    ~LoginForm();
    void UpdateTable();
    void SetNewDBPath(QString new_path);

private slots:
    void on_pushButton_clicked();

    void on_add_button_clicked();

private:
     QSqlDatabase db;
     QString m_db_path= "D:\\QTProj\\PasswordManager\\proj.db";
    Ui::LoginForm *ui;
};
#endif // LOGINFORM_H

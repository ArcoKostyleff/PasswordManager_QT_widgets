#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "ui_LoginForm.h"
#include "addrowform.h"
QT_BEGIN_NAMESPACE
namespace Ui { class LoginForm; }
QT_END_NAMESPACE

class LoginForm : public QWidget
{
    Q_OBJECT

public:

   // static LoginForm *loginForm_ptr = this;

    LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

    void UpdateTable();
    void SetNewDBPath(QString new_path);
    void findPassword(QString name);
public slots:
    void recieveData(QString name, QString login, QString pass);
private slots:
    void on_pushButton_clicked();

    void on_add_button_clicked();
    void on_loginLine_textChanged(const QString &arg1);

    void on_findButton_clicked();

signals:
    void s_loggined();
private:
     QSqlDatabase db;
     QPushButton *qb;
     AddRowForm *m_addrowform_ptr;

     QString m_db_path= "proj2.db";
    Ui::LoginForm *ui;
};
#endif // LOGINFORM_H

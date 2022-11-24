#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QMap>
#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "LoginForm.h"
#include "registerform.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
     void recieveData(QString login, QString password);
private slots:

    void on_login_Button_clicked();

    void on_registration_button_clicked();
private:
    void updateUsers();
signals:
    void s_registrated();
private:
     LoginForm *m_login_form_ptr;
     RegisterForm *m_register_form_ptr;
     QSqlDatabase db;
     QMap<QString, QString> m_users_map;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

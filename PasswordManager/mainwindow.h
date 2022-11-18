#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QMap>
#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "LoginForm.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_login_Button_clicked();

private:
     LoginForm *m_login_form_ptr;
     QSqlDatabase db;
     QMap<QString, QString> m_users_map;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

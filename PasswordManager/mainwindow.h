#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QMap>
#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
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
     QSqlDatabase db;
     QMap<QString, QString> m_users_map;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

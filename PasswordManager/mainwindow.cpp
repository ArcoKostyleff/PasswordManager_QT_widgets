#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    qDebug() << "go on";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\QTProj\\PasswordManager\\proj.db");
    db.open();
    QSqlQuery query;
    query.exec("SELECT id, u_login, u_password FROM users");

    while (query.next()) { qDebug() << "2";
      QString _id = query.value(0).toString();
      QString login = query.value(1).toString();
      QString password = query.value(2).toString();
      m_users_map.insert(login, password);
      qDebug() << login << " "<< password ;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_loginButton_clicked()
//{

//    QString login_st = ui->loginLine->text();
//    QString password_st = ui->passwordLine->text();
//   // if(m_users_map.find(login_str)!= m_users_map.end()){
//        // find users in db

//    //}else  ui->auth_text->setText("govno!");
//}



void MainWindow::on_login_Button_clicked()
{
    qDebug() << 1 << " "<< 1 ;

    QString login_st = ui->loginLine->text();
    QString password_st = ui->passwordLine->text();
     qDebug() << login_st << " "<< password_st ;
    if(m_users_map.find(login_st)!= m_users_map.end()){
        ui->auth_text->setText("successfull!");

    }else  ui->auth_text->setText("govno!");
}


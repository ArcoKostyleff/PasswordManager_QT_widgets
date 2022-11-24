#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    m_login_form_ptr = new LoginForm();
    connect(m_login_form_ptr, &LoginForm::s_loggined, this, &MainWindow::show);

    qDebug() << "go on";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\QTProj\\PasswordManager\\proj2.db");
    db.open();
    qDebug()<<"aboba " <<db.lastError().text();

    updateUsers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recieveData(QString login, QString password)
{
    qDebug()<< login <<" "<< password;

    QSqlQuery query(db);
    query.exec();
    if(!query.exec("INSERT INTO users ( u_login, u_password) VALUES ('"+login+"', '"+password+"')")) qDebug() <<"Error putting values: "<<query.lastError().text();

}

void MainWindow::on_login_Button_clicked()
{
    updateUsers();

    QString login_st = ui->loginLine->text();
    QString password_st = ui->passwordLine->text();
     qDebug() << login_st << " "<< password_st ;
    if(m_users_map.find(login_st)!= m_users_map.end()){
        ui->auth_text->setText("successfull!");
        m_login_form_ptr -> show();
        this->close();
    }else  {
        ui->auth_text->setStyleSheet("QLabel { background-color : white; color : red; }");
        ui->loginLine->setStyleSheet("QLineEdit {background-color : white; color : red; }");
        ui->passwordLine->setStyleSheet("QLineEdit {background-color : white; color : red; }");
        ui->auth_text->setText("wrong login/password!");

    }
}


void MainWindow::on_registration_button_clicked()
{
    m_register_form_ptr = new RegisterForm(this);
if (connect(m_register_form_ptr, &RegisterForm::SendData, this, &MainWindow::recieveData)){
    qDebug() << "ok";
     m_register_form_ptr->setModal(true);

     m_register_form_ptr->show();
}
else qDebug()<<"Erora";
}

void MainWindow::updateUsers()
{
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


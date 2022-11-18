#include "LoginForm.h"
#include "ui_LoginForm.h"
#include <QString>
LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_db_path);
    db.open();

    QPushButton qb;

   UpdateTable();
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::UpdateTable()
{    QSqlQuery query;
     query.exec("SELECT id, name, login, password FROM passwords");
      ui->tableWidget->clear();
       ui->tableWidget->setRowCount(0);
     while (query.next()) {
       QString _id = query.value(0).toString();
       QString name = query.value(1).toString();
       QString login = query.value(2).toString();
       QString password = query.value(3).toString();
       ui->tableWidget->insertRow(ui->tableWidget->rowCount());
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,  new QTableWidgetItem(name) );
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,  new QTableWidgetItem(login) );
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,  new QTableWidgetItem(password) );
       }
     ui->tableWidget->update();

}

void LoginForm::SetNewDBPath(QString new_path)
{
m_db_path = new_path;
}


void LoginForm::on_pushButton_clicked()
{

    UpdateTable();

}


void LoginForm::on_add_button_clicked()
{

}


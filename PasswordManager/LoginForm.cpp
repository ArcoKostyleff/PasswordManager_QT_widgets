#include "LoginForm.h"
#include "ui_LoginForm.h"
#include <QString>
LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);


   // connect(m_addrowform_ptr, &AddRowForm::SendData, this, &LoginForm::show);


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_db_path);
    db.open();


    ui->tableWidget->insertColumn(3);
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
        qb = new QPushButton();
        qb->setParent(ui->tableWidget);
        qb->setIconSize(QSize(50,50));
        qb->setText("delete");
       QString _id = query.value(0).toString();
       QString name = query.value(1).toString();
       QString login = query.value(2).toString();
       QString password = query.value(3).toString();
       ui->tableWidget->insertRow(ui->tableWidget->rowCount());
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,  new QTableWidgetItem(name) );
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,  new QTableWidgetItem(login) );
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,  new QTableWidgetItem(password) );
       ui-> tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 3, qb);
       }
     ui->tableWidget->update();

}

void LoginForm::SetNewDBPath(QString new_path)
{
    m_db_path = new_path;
}

void LoginForm::findPassword(QString name)
{
    QList finded = ui->tableWidget->findItems(name, Qt::MatchContains);
    for(auto t: finded){
        QBrush qb;
        //TODO: find elements end fill them by some color
    }
    qDebug()<<"finded: "<< finded.size();
}

void LoginForm::recieveData(QString name, QString login, QString pass)
{
    qDebug() << name << " "<< login <<" "<< pass;
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
    qDebug()<<rowCount;
    QTableWidgetItem *itemName =ui->tableWidget->item(rowCount-1, 0);
    QTableWidgetItem *itemLogin =ui->tableWidget->item(rowCount-1, 1);
    QTableWidgetItem *itemPass =ui->tableWidget->item(rowCount-1, 2);

    itemName->setText(name);
    itemLogin->setText(login);
    itemPass->setText(pass);

    QSqlQuery query;
    qDebug()<<rowCount;
    if(!query.exec("INSERT INTO passwords (id, name, login, password) VALUES ('"+QString::number(rowCount+1)+"', '"+name+"', '"+login+"', '"+pass+"')")) qDebug() <<"Error putting values";
    UpdateTable();
}


void LoginForm::on_pushButton_clicked()
{

    UpdateTable();

}


void LoginForm::on_add_button_clicked()
{
   // m_addrowform_ptr = new AddRowForm(this);
    m_addrowform_ptr = new AddRowForm(this);
   if( connect(m_addrowform_ptr, &AddRowForm::SendData,this, &LoginForm::recieveData)) qDebug()<<"ok";
   else qDebug()<<"Erora";
    m_addrowform_ptr->setModal(true);

    m_addrowform_ptr->show();
}




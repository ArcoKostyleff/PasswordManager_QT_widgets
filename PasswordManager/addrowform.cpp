#include "addrowform.h"
#include "ui_addrowform.h"

AddRowForm::AddRowForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowForm)
{

    ui->setupUi(this);
   // connect(this, SIGNAL(sendData(QString, QString,QString)),parent, SLOT(recieveData(QString, QString,QString)));
 //   if (connect(this, SIGNAL(sendData(QString, QString,QString)),parent, SLOT(recieveData(QString, QString,QString)))) qDebug()<<"OK";
 //   else qDebug() <<"connection is failed!";
}

AddRowForm::~AddRowForm()
{
    delete ui;
}

void AddRowForm::on_add_new_button_clicked()
{


    if (!ui->add_name_line->text().isEmpty() && !ui->add_login_line->text().isEmpty() && !ui->add_password_line->text().isEmpty()){
        qDebug()<<"es";
        emit SendData(ui->add_name_line->text(), ui->add_login_line->text(), ui->add_password_line->text());
        qDebug()<<"se";
        this->close();
    }
    else {
        qDebug() <<" style ";
        if (ui->add_name_line->text().isEmpty()){ ui->add_name_line->setStyleSheet("color : black; background-color : red;"); }
        if (ui->add_login_line->text().isEmpty()) ui->add_login_line->setStyleSheet("color : black; background-color : red;");
        if (ui->add_password_line->text().isEmpty()) ui->add_password_line->setStyleSheet("color : black; background-color : red;");
    }
}


void AddRowForm::on_add_name_line_textChanged(const QString &arg1)
{
    if (!arg1.isEmpty()){ ui->add_name_line->setStyleSheet("color : black; background-color : white;");}
}


void AddRowForm::on_add_login_line_textChanged(const QString &arg1)
{
    if (!arg1.isEmpty()){ ui->add_login_line->setStyleSheet("color : black; background-color : white;");}
}



void AddRowForm::on_add_password_line_textChanged(const QString &arg1)
{
    if (!arg1.isEmpty()){ ui->add_password_line->setStyleSheet("color : black; background-color : white;");}
}


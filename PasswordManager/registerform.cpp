#include "registerform.h"
#include "ui_registerform.h"

RegisterForm::RegisterForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

void RegisterForm::on_registerButton_clicked()
{
    if (!ui->loginRegisterLine->text().isEmpty() && !ui->passwordRegisterLine->text().isEmpty()){
        qDebug()<<"es";
        emit SendData(ui->loginRegisterLine->text(), ui->passwordRegisterLine->text());
        qDebug()<<"se";
        this->close();
    }
    else {
        qDebug() <<" style ";
        if (ui->loginRegisterLine->text().isEmpty()){ ui->loginRegisterLine->setStyleSheet("color : black; background-color : red;"); }
        if (ui->passwordRegisterLine->text().isEmpty()) ui->passwordRegisterLine->setStyleSheet("color : black; background-color : red;");
        }
}


void RegisterForm::on_loginRegisterLine_textChanged(const QString &arg1)
{
if (!arg1.isEmpty()){ ui->loginRegisterLine->setStyleSheet("color : black; background-color : white;");}
}


void RegisterForm::on_passwordRegisterLine_textChanged(const QString &arg1)
{
if (!arg1.isEmpty()){ ui->passwordRegisterLine->setStyleSheet("color : black; background-color : white;");}
}


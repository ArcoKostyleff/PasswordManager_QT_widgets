#ifndef ADDROWFORM_H
#define ADDROWFORM_H

#include <QWidget>
#include <QDialog>
namespace Ui {
class AddRowForm;
}

class AddRowForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddRowForm(QWidget *parent = nullptr);
    ~AddRowForm();

private slots:
    void on_add_new_button_clicked();

    void on_add_name_line_textChanged(const QString &arg1);

    void on_add_login_line_textChanged(const QString &arg1);

    void on_add_password_line_textChanged(const QString &arg1);

signals:
    void SendData(QString name, QString login, QString pass);
private:
    Ui::AddRowForm *ui;
};

#endif // ADDROWFORM_H

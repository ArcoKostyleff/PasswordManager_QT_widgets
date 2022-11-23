    #ifndef REGISTERFORM_H
    #define REGISTERFORM_H

    #include <QWidget>
    #include <QDialog>
    namespace Ui {
    class RegisterForm;
    }

    class RegisterForm : public QDialog
    {
        Q_OBJECT

    public:
        explicit RegisterForm(QWidget *parent = nullptr);
        ~RegisterForm();

    private slots:
        void on_registerButton_clicked();

        void on_loginRegisterLine_textChanged(const QString &arg1);

        void on_passwordRegisterLine_textChanged(const QString &arg1);

    signals:
        void SendData(QString login, QString pass);
    private:
        Ui::RegisterForm *ui;
    };

    #endif // REGISTERFORM_H

#include "registrationwindow.h"
#include "ui_registrationwindow.h"

#include <QMessageBox>

RegistrationWindow::RegistrationWindow(std::vector<User>& users, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow),
    m_users(users)
{
    ui->setupUi(this);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_reg_create_push_button_clicked()
{
    std::string username = ui->reg_username_line_edit->text().toStdString();
    std::string password = ui->reg_password_line_edit->text().toStdString();

    if (username == "" || password == "") {
        QMessageBox::information(this, "User Message !", "Username or Password fields are empty !");
        return;
    }

    for (auto i : m_users) {
        if (username == i.get_user_name()) {
            QMessageBox::information(this, "User Message !", "Username already exists !");
            return;
        }
    }

    m_users.push_back(User(username, password, m_users.size()));
    this->close();
}


#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "fileload.h"
#include "registrationwindow.h"
#include "filesave.h"
#include "programwindow.h"

#include <QMessageBox>

#include <iostream>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    FileLoad loader;
    m_users = loader.load_users_file_txt(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_log_sign_in_push_button_clicked()
{
    std::string username = ui->log_username_line_edit->text().toStdString();
    std::string password = ui->log_password_line_edit->text().toStdString();

//    for (auto i : m_users) {
//        std::cout << i.get_user_name() << " " << i.get_user_password() << " " << i.get_user_id() << "\n";
//    }

    for (auto i : m_users) {
        if (username == i.get_user_name() && password == i.get_user_password()) {
            FileSave saver;
            saver.save_users_file_txt(m_users);
            this->close();
            ProgramWindow prog_window(i);
            prog_window.setModal(true);
            prog_window.exec();
            return;
        }
    }
    QMessageBox::information(this, "User Message !", "Username or Password is wrong, please try again !");
}

void LoginWindow::on_log_create_user_push_button_clicked()
{
    RegistrationWindow reg_window(m_users);
    reg_window.setModal(true);
    reg_window.exec();
}


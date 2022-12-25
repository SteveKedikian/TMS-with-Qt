#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "user.h"

#include <QMainWindow>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_log_sign_in_push_button_clicked();
    void on_log_create_user_push_button_clicked();

private:
    Ui::LoginWindow *ui;
    std::vector<User> m_users;
};
#endif // LOGINWINDOW_H

#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include "user.h"
#include <vector>

#include <QDialog>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(std::vector<User>&, QWidget *parent = nullptr);
    ~RegistrationWindow();

private slots:
    void on_reg_create_push_button_clicked();

private:
    Ui::RegistrationWindow *ui;
    std::vector<User>& m_users;
};

#endif // REGISTRATIONWINDOW_H

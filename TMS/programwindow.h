#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <QDialog>
#include <vector>

#include "user.h"
#include "project.h"

namespace Ui {
class ProgramWindow;
}

class ProgramWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramWindow(User& user, QWidget *parent = nullptr);
    ~ProgramWindow();

private slots:
    void on_proj_status_push_button_clicked();

    void on_proj_edit_push_button_clicked();

    void on_proj_logout_push_button_clicked();

    void on_proj_create_push_button_clicked();

    void on_proj_investigate_push_button_clicked();

    void on_proj_about_push_button_clicked();

private:
    Ui::ProgramWindow *ui;
    User m_prog_user;
    std::vector<Project> m_prog_projects;
};

#endif // PROGRAMWINDOW_H

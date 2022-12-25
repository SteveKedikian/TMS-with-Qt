#ifndef TASKPROGRAMWINDOW_H
#define TASKPROGRAMWINDOW_H

#include "task.h"

#include <QDialog>
#include <vector>

namespace Ui {
class TaskProgramWindow;
}

class TaskProgramWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TaskProgramWindow(std::vector<Task>&, QWidget *parent = nullptr);
    ~TaskProgramWindow();

private slots:
    void on_task_status_push_button_clicked();

    void on_task_edit_push_button_clicked();

    void on_task_logout_push_button_clicked();

    void on_task_create_push_button_clicked();

    void on_task_about_push_button_clicked();

private:
    Ui::TaskProgramWindow *ui;
    std::vector<Task>& m_prog_tasks;
};

#endif // TASKPROGRAMWINDOW_H

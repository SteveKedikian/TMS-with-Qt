#include "taskprogramwindow.h"
#include "ui_taskprogramwindow.h"
#include "statuschangewindow.h"
#include "projecteditwindow.h"
#include "projectcreatewindow.h"
#include "projaboutwindow.h"

#include <string>

TaskProgramWindow::TaskProgramWindow(std::vector<Task>& tasks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskProgramWindow),
    m_prog_tasks{tasks}
{
    ui->setupUi(this);

    for (unsigned int i = 0; i < tasks.size(); ++i) {
        ui->task_list_widget->addItem(QString::fromStdString(std::to_string(i + 1) + "   " + tasks[i].get_task_title()
                                                             + "           " + tasks[i].get_task_status()));
    }
}

TaskProgramWindow::~TaskProgramWindow()
{
    delete ui;
}

void TaskProgramWindow::on_task_status_push_button_clicked()
{
    std::string status;
    int row_index = ui->task_list_widget->currentRow();
    int status_num = 0;

    StatusChangeWindow status_window(status_num);
    status_window.setModal(true);
    status_window.exec();

    if (status_num == 0) {
        return;
    }
    else if (status_num == 1) {
        status = "Done";
    }
    else if (status_num == 2) {
        status = "In_Process";
    }
    else if (status_num == 3) {
        status = "Waiting";
    }
    else if (status_num == 4) {
        status = "Delete";
    }

    m_prog_tasks[row_index].set_task_status(status);
    ui->task_list_widget->currentItem()->setText(QString::fromStdString(std::to_string(row_index + 1) + "   " + m_prog_tasks[row_index].get_task_title()
                                                         + "           " + m_prog_tasks[row_index].get_task_status()));
}


void TaskProgramWindow::on_task_edit_push_button_clicked()
{
    int row_index = ui->task_list_widget->currentRow();
    std::string title = m_prog_tasks[row_index].get_task_title();
    std::string description = m_prog_tasks[row_index].get_task_description();


    ProjectEditWindow edit_window(title, description);
    edit_window.setModal(true);
    edit_window.exec();

    m_prog_tasks[row_index].set_task_title(title);
    m_prog_tasks[row_index].set_task_description(description);
    ui->task_list_widget->currentItem()->setText(QString::fromStdString(std::to_string(row_index + 1) + "   " + m_prog_tasks[row_index].get_task_title()
                                                         + "           " + m_prog_tasks[row_index].get_task_status()));
}


void TaskProgramWindow::on_task_logout_push_button_clicked()
{
    this->close();
}


void TaskProgramWindow::on_task_create_push_button_clicked()
{
    std::string title = "#_)!!)*%";
    std::string description = "^&))@#";
    std::string status = "Waiting";
    int id = m_prog_tasks.size();

    ProjectCreateWindow create_window(title, description);
    create_window.setModal(true);
    create_window.exec();

    if (title == "#_)!!)*%" || description == "^&))@#") {
        return;
    }

    m_prog_tasks.push_back(Task(title, description, status, id));
    ui->task_list_widget->addItem(QString::fromStdString(std::to_string(id + 1) + "   " + m_prog_tasks[id].get_task_title()
                                                         + "           " + m_prog_tasks[id].get_task_status()));
}

void TaskProgramWindow::on_task_about_push_button_clicked()
{
    int row_index = ui->task_list_widget->currentRow();
    std::string title = m_prog_tasks[row_index].get_task_title();
    std::string status = m_prog_tasks[row_index].get_task_status();
    std::string description = m_prog_tasks[row_index].get_task_description();

    ProjAboutWindow about_window(title, status, description);
    about_window.setModal(true);
    about_window.exec();
}


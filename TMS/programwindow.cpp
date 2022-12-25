#include "programwindow.h"
#include "ui_programwindow.h"
#include "fileload.h"
#include "task.h"
#include "filesave.h"
#include "statuschangewindow.h"
#include "projecteditwindow.h"
#include "projectcreatewindow.h"
#include "taskprogramwindow.h"
#include "projaboutwindow.h"

#include <QMessageBox>
#include <string>
#include <vector>

#include <fstream>
#include <iostream>
ProgramWindow::ProgramWindow(User& user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgramWindow),
    m_prog_user{user}
{
    ui->setupUi(this);

    FileLoad proj_loader;
    m_prog_projects = proj_loader.load_projects_file_txt(parent, user.get_user_id());

    FileLoad task_loader;
    std::vector<Task> tasks;

    for (unsigned int i = 0; i < m_prog_projects.size(); ++i) {
        tasks = task_loader.load_tasks_file_txt(parent, user.get_user_id(), m_prog_projects[i].get_project_id());
        for (unsigned int j = 0; j < tasks.size(); ++j) {
            m_prog_projects[i].add_task(tasks[j]);
        }
    }

    for (unsigned int i = 0; i < m_prog_projects.size(); ++i) {
        ui->proj_list_widget->addItem(QString::fromStdString(std::to_string(i + 1) + "   " + m_prog_projects[i].get_project_title()
                                                             + "           " + m_prog_projects[i].get_project_status()));
    }

//    QMessageBox::information(this, "title: ", QString::fromStdString(m_prog_projects[1].get_project_task_title(2)));
//    QMessageBox::information(this, "desc: ", QString::fromStdString(m_prog_projects[1].get_project_task_description(2)));
//    QMessageBox::information(this, "status: ", QString::fromStdString(m_prog_projects[1].get_project_task_status(2)));
//    QMessageBox::information(this, "id: ", QString::fromStdString(std::to_string(m_prog_projects[1].get_project_task_id(2))));

//    QMessageBox::information(this, "user: ", QString::fromStdString(user.get_user_name()));
//    QMessageBox::information(this, "user: ", QString::fromStdString(user.get_user_password()));
//    QMessageBox::information(this, "user: ", QString::fromStdString(std::to_string(user.get_user_id())));

//    QMessageBox::information(this, "title: ", QString::fromStdString(m_prog_projects[0].get_project_title()));
//    QMessageBox::information(this, "desc: ", QString::fromStdString(m_prog_projects[0].get_project_description()));
//    QMessageBox::information(this, "status: ", QString::fromStdString(m_prog_projects[0].get_project_status()));
//    QMessageBox::information(this, "id: ", QString::fromStdString(std::to_string(m_prog_projects[0].get_project_id())));

//    QMessageBox::information(this, "title: ", QString::fromStdString(m_prog_projects[1].get_project_title()));
//    QMessageBox::information(this, "desc: ", QString::fromStdString(m_prog_projects[1].get_project_description()));
//    QMessageBox::information(this, "status: ", QString::fromStdString(m_prog_projects[1].get_project_status()));
//    QMessageBox::information(this, "id: ", QString::fromStdString(std::to_string(m_prog_projects[1].get_project_id())));

//    QMessageBox::information(this, "title: ", QString::fromStdString(m_prog_projects[2].get_project_title()));
//    QMessageBox::information(this, "desc: ", QString::fromStdString(m_prog_projects[2].get_project_description()));
//    QMessageBox::information(this, "status: ", QString::fromStdString(m_prog_projects[2].get_project_status()));
//    QMessageBox::information(this, "id: ", QString::fromStdString(std::to_string(m_prog_projects[2].get_project_id())));
}

ProgramWindow::~ProgramWindow()
{
    FileSave saver;
    saver.save_projects_file_txt(m_prog_projects, m_prog_user.get_user_id());
    delete ui;
}

void ProgramWindow::on_proj_status_push_button_clicked()
{
    std::string status;
    int row_index = ui->proj_list_widget->currentRow();
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

    m_prog_projects[row_index].set_project_status(status);
    ui->proj_list_widget->currentItem()->setText(QString::fromStdString(std::to_string(row_index + 1) + "   " + m_prog_projects[row_index].get_project_title()
                                                         + "           " + m_prog_projects[row_index].get_project_status()));
}

void ProgramWindow::on_proj_edit_push_button_clicked()
{
    int row_index = ui->proj_list_widget->currentRow();
    std::string title = m_prog_projects[row_index].get_project_title();
    std::string description = m_prog_projects[row_index].get_project_description();


    ProjectEditWindow edit_window(title, description);
    edit_window.setModal(true);
    edit_window.exec();

    m_prog_projects[row_index].set_project_title(title);
    m_prog_projects[row_index].set_project_description(description);
    ui->proj_list_widget->currentItem()->setText(QString::fromStdString(std::to_string(row_index + 1) + "   " + m_prog_projects[row_index].get_project_title()
                                                         + "           " + m_prog_projects[row_index].get_project_status()));
}

void ProgramWindow::on_proj_logout_push_button_clicked()
{
    this->close();
}

void ProgramWindow::on_proj_create_push_button_clicked()
{
    std::string title = "#_)!!)*%";
    std::string description = "^&))@#";
    std::string status = "Waiting";
    int id;

    if (m_prog_projects.empty()) {
        id = 0;
    }
    else {
        id = m_prog_projects[m_prog_projects.size() - 1].get_project_id() + 1;
    }

    ProjectCreateWindow create_window(title, description);
    create_window.setModal(true);
    create_window.exec();

    if (title == "#_)!!)*%" || description == "^&))@#") {
        return;
    }

    m_prog_projects.push_back(Project(title, description, status, id));
    ui->proj_list_widget->addItem(QString::fromStdString(std::to_string(m_prog_projects.size()) + "   " + m_prog_projects[m_prog_projects.size() - 1].get_project_title()
                                                         + "           " + m_prog_projects[m_prog_projects.size() - 1].get_project_status()));
}

void ProgramWindow::on_proj_investigate_push_button_clicked()
{
    int row_index = ui->proj_list_widget->currentRow();
    TaskProgramWindow task_window(m_prog_projects[row_index].get_project_tasks());
    task_window.setModal(true);
    task_window.exec();
}


void ProgramWindow::on_proj_about_push_button_clicked()
{
    int row_index = ui->proj_list_widget->currentRow();
    std::string title = m_prog_projects[row_index].get_project_title();
    std::string status = m_prog_projects[row_index].get_project_status();
    std::string description = m_prog_projects[row_index].get_project_description();

    ProjAboutWindow about_window(title, status, description);
    about_window.setModal(true);
    about_window.exec();
}


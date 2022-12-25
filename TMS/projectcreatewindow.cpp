#include "projectcreatewindow.h"
#include "ui_projectcreatewindow.h"

#include <string>
#include <QMessageBox>

ProjectCreateWindow::ProjectCreateWindow(std::string& title, std::string& description, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectCreateWindow),
    m_title{title},
    m_description{description}
{
    ui->setupUi(this);
}

ProjectCreateWindow::~ProjectCreateWindow()
{
    delete ui;
}

void ProjectCreateWindow::on_proj_create_cancel_push_button_clicked()
{
    this->close();
}


void ProjectCreateWindow::on_proj_create_save_push_button_clicked()
{
    std::string title = ui->proj_create_title_line_label->text().toStdString();
    std::string description = ui->proj_create_description_text_edit->toPlainText().toStdString();

    for (unsigned int i = 0; i < title.length(); ++i) {
        if (title[i] == ' ') {
            QMessageBox::information(this, "User Message !", "Title of the Project must not contain any spaces ! Use underscore '_' instead !");
            return;
        }
    }

    if (m_title.empty()) {
        QMessageBox::information(this, "User Message !", "Project Title can't be empty !");
        return;
    }

    if (m_description.empty()) {
        QMessageBox::information(this, "User Message !", "Project Description can't be empty !");
        return;
    }

    m_title = title;
    m_description = description;
    this->close();
}


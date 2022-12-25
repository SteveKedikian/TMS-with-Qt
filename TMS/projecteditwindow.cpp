#include "projecteditwindow.h"
#include "ui_projecteditwindow.h"

#include <string>
#include <QMessageBox>
#include <QLineEdit>

#include <iostream>
ProjectEditWindow::ProjectEditWindow(std::string& title, std::string& description, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectEditWindow),
    m_title{title},
    m_description{description}
{
    ui->setupUi(this);
    ui->proj_edit_title_line_label->setText(QString::fromStdString(m_title));
    ui->proj_edit_description_text_edit->setText(QString::fromStdString(m_description));
}

ProjectEditWindow::~ProjectEditWindow()
{
    delete ui;
}

void ProjectEditWindow::on_proj_edit_cancel_push_button_clicked()
{
    this->close();
}


void ProjectEditWindow::on_proj_edit_save_push_button_clicked()
{
    std::string title_check = ui->proj_edit_title_line_label->text().toStdString();
    for (unsigned int i = 0; i < title_check.length(); ++i) {
        if (title_check[i] == ' ') {
            QMessageBox::information(this, "User Message !", "Title of the Project must not contain any spaces ! Use underscore '_' instead !");
            return;
        }
    }

    m_title = ui->proj_edit_title_line_label->text().toStdString();
    m_description = ui->proj_edit_description_text_edit->toPlainText().toStdString();
    std::cout << m_description << "\n";
    this->close();
}


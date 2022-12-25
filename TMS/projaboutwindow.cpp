#include "projaboutwindow.h"
#include "ui_projaboutwindow.h"

ProjAboutWindow::ProjAboutWindow(std::string& title, std::string& status, std::string& description, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjAboutWindow),
    m_title{title},
    m_status{status},
    m_description{description}
{
    ui->setupUi(this);

    ui->about_title_and_status_label->setText(QString::fromStdString("Title: " + title + "        status: " + status));
    ui->about_description_text_browser->setText(QString::fromStdString(description));
}

ProjAboutWindow::~ProjAboutWindow()
{
    delete ui;
}

void ProjAboutWindow::on_about_close_push_button_clicked()
{
    this->close();
}


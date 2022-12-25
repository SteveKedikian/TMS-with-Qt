#include "statuschangewindow.h"
#include "ui_statuschangewindow.h"

#include <iostream>

StatusChangeWindow::StatusChangeWindow(int& status_num, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatusChangeWindow),
    m_status_num{status_num}
{
    ui->setupUi(this);
}

StatusChangeWindow::~StatusChangeWindow()
{
    std::cout << "\nI closed with: " << m_status_num << "\n";
    delete ui;
}

void StatusChangeWindow::on_status_done_push_button_clicked()
{
    m_status_num = 1;
    this->close();
}


void StatusChangeWindow::on_status_inprocess_push_button_clicked()
{
    m_status_num = 2;
    this->close();
}


void StatusChangeWindow::on_status_waiting_push_button_clicked()
{
    m_status_num = 3;
    this->close();
}


void StatusChangeWindow::on_status_deleted_push_button_clicked()
{
    m_status_num = 4;
    this->close();
}


void StatusChangeWindow::on_status_cancel_push_button_clicked()
{
    m_status_num = 0;
    this->close();
}


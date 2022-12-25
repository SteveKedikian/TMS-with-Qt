#ifndef STATUSCHANGEWINDOW_H
#define STATUSCHANGEWINDOW_H

#include <QDialog>

namespace Ui {
class StatusChangeWindow;
}

class StatusChangeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatusChangeWindow(int&, QWidget *parent = nullptr);
    ~StatusChangeWindow();

private slots:
    void on_status_done_push_button_clicked();

    void on_status_inprocess_push_button_clicked();

    void on_status_waiting_push_button_clicked();

    void on_status_deleted_push_button_clicked();

    void on_status_cancel_push_button_clicked();

private:
    Ui::StatusChangeWindow *ui;
    int& m_status_num;
};

#endif // STATUSCHANGEWINDOW_H

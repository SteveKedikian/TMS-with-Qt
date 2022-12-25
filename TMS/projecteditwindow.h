#ifndef PROJECTEDITWINDOW_H
#define PROJECTEDITWINDOW_H

#include <QDialog>
#include <string>

namespace Ui {
class ProjectEditWindow;
}

class ProjectEditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectEditWindow(std::string&, std::string&, QWidget *parent = nullptr);
    ~ProjectEditWindow();

private slots:
    void on_proj_edit_cancel_push_button_clicked();

    void on_proj_edit_save_push_button_clicked();

private:
    Ui::ProjectEditWindow *ui;
    std::string& m_title;
    std::string& m_description;
};

#endif // PROJECTEDITWINDOW_H

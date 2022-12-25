#ifndef PROJECTCREATEWINDOW_H
#define PROJECTCREATEWINDOW_H

#include <QDialog>

namespace Ui {
class ProjectCreateWindow;
}

class ProjectCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectCreateWindow(std::string&, std::string&, QWidget *parent = nullptr);
    ~ProjectCreateWindow();

private slots:
    void on_proj_create_cancel_push_button_clicked();

    void on_proj_create_save_push_button_clicked();

private:
    Ui::ProjectCreateWindow *ui;
    std::string& m_title;
    std::string& m_description;
};

#endif // PROJECTCREATEWINDOW_H

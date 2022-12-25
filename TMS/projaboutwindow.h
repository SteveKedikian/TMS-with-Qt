#ifndef PROJABOUTWINDOW_H
#define PROJABOUTWINDOW_H

#include <QDialog>

namespace Ui {
class ProjAboutWindow;
}

class ProjAboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProjAboutWindow(std::string&, std::string&, std::string&, QWidget *parent = nullptr);
    ~ProjAboutWindow();

private slots:
    void on_about_close_push_button_clicked();

private:
    Ui::ProjAboutWindow *ui;
    std::string m_title;
    std::string m_status;
    std::string m_description;
};

#endif // PROJABOUTWINDOW_H

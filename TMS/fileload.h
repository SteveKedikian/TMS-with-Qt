#ifndef FILELOAD_H
#define FILELOAD_H

#include "user.h"
#include "project.h"
#include "task.h"

#include <vector>
#include <QWidget>

class FileLoad
{
public:
    FileLoad();

    void check_users_file_txt(QWidget*);
    std::vector<User> load_users_file_txt(QWidget*);
    std::vector<Project> load_projects_file_txt(QWidget*, int user_id);
    std::vector<Task> load_tasks_file_txt(QWidget*, int user_id, int project_id);

private:
    std::vector<User> m_file_users;
    std::vector<Task> m_file_tasks;
    std::vector<Project> m_file_projects;
};

#endif // FILELOAD_H

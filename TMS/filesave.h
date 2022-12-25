#ifndef FILESAVE_H
#define FILESAVE_H

#include "user.h"
#include "project.h"
#include "task.h"

#include <vector>

class FileSave
{
public:
    FileSave();

    void save_users_file_txt(std::vector<User>&);
    void save_projects_file_txt(std::vector<Project>&, int);
    void save_tasks_file_txt(std::vector<Task>&, int, int);
};

#endif // FILESAVE_H

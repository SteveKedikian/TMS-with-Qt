#ifndef PROJECT_H
#define PROJECT_H

#include "task.h"

#include <string>
#include <vector>

class Project
{
public:
    Project();
    Project(const std::string&, const std::string&, const std::string&, int);

    void set_project_title(std::string&);
    void set_project_description(std::string&);
    void set_project_status(std::string&);
    void set_project_id(int);
    void set_project_task_title(std::string&, int);
    void set_project_task_description(std::string&, int);
    void set_project_task_status(std::string&, int);
    void set_project_task_id(int, int);
    void set_project_tasks_size(int);
    void add_task(Task&);

    std::string get_project_title();
    std::string get_project_description();
    std::string get_project_status();
    int get_project_id();
    std::string get_project_task_title(int);
    std::string get_project_task_description(int);
    std::string get_project_task_status(int);
    int get_project_task_id(int);
    std::vector<Task>& get_project_tasks();

private:
    std::string m_title;
    std::string m_description;
    std::string m_status;
    std::vector<Task> m_tasks;
    int m_id;
};

#endif // PROJECT_H

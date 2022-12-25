#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
public:
    Task();
    Task(const std::string&, const std::string&, const std::string&, int);
//    Task(std::string, std::string, std::string, int);

    Task(const Task& task)
        : m_title{task.m_title}
        , m_description{task.m_description}
        , m_status{task.m_status}
        , m_id{task.m_id}
    {}

    Task(Task&& task)
        : m_title{task.m_title}
        , m_description{task.m_description}
        , m_status{task.m_status}
        , m_id{task.m_id}
    {}

    Task& operator=(const Task& task) {
        m_title = task.m_title;
        m_description = task.m_description;
        m_status = task.m_status;
        m_id = task.m_id;
        return *this;
    }

    Task& operator=(Task&& task) {
        m_title = task.m_title;
        m_description = task.m_description;
        m_status = task.m_status;
        m_id = task.m_id;
        return *this;
    }

    void set_task_title(std::string&);
    void set_task_description(std::string&);
    void set_task_status(std::string&);
    void set_task_id(int);
    std::string get_task_title();
    std::string get_task_description();
    std::string get_task_status();
    int get_task_id();

private:
    std::string m_title;
    std::string m_description;
    std::string m_status;
    int m_id;
};

#endif // TASK_H

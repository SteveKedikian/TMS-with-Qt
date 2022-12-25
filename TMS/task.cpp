#include "task.h"

Task::Task()
    : m_title{}
    , m_description{}
    , m_status{}
    , m_id{}
{}

Task::Task(const std::string& title, const std::string& description, const std::string& status, int id)
    : m_title{title}
    , m_description{description}
    , m_status{status}
    , m_id{id}
{}

//Task::Task(std::string title, std::string description, std::string status, int id)
//    : m_title{title}
//    , m_description{description}
//    , m_status{status}
//    , m_id{id}
//{}

void Task::set_task_title(std::string& title) {m_title = title;}

void Task::set_task_description(std::string& description) {m_description = description;}

void Task::set_task_status(std::string& status) {m_status = status;}

void Task::set_task_id(int id) {m_id = id;}

std::string Task::get_task_title() {return m_title;}

std::string Task::get_task_description() {return m_description;}

std::string Task::get_task_status() {return m_status;}

int Task::get_task_id() {return m_id;}

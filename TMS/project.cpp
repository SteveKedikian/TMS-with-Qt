#include "project.h"
#include "task.h"

Project::Project()
{}

Project::Project(const std::string& title, const std::string& description, const std::string& status, int id)
    : m_title{title}
    , m_description{description}
    , m_status{status}
    , m_tasks{}
    , m_id{id}
{}

void Project::set_project_title(std::string& title) {m_title = title;}

void Project::set_project_description(std::string& description) {m_description = description;}

void Project::set_project_status(std::string& status) {m_status = status;}

void Project::set_project_id(int id) {m_id = id;}

void Project::set_project_task_title(std::string& title, int index) {m_tasks[index].set_task_title((title));}

void Project::set_project_task_description(std::string& description, int index) {m_tasks[index].set_task_description((description));}

void Project::set_project_task_status(std::string& status, int index) {m_tasks[index].set_task_status((status));}

void Project::set_project_task_id(int id, int index) {m_tasks[index].set_task_id((id));}

void Project::set_project_tasks_size(int size) {m_tasks.resize(size);}



std::string Project::get_project_title() {return m_title;}

std::string Project::get_project_description() {return m_description;}

std::string Project::get_project_status() {return m_status;}

int Project::get_project_id() {return m_id;}

std::string Project::get_project_task_title(int index) {return m_tasks[index].get_task_title();}

std::string Project::get_project_task_description(int index) {return m_tasks[index].get_task_description();}

std::string Project::get_project_task_status(int index) {return m_tasks[index].get_task_status();}

int Project::get_project_task_id(int index) {return m_tasks[index].get_task_id();};

std::vector<Task>& Project::get_project_tasks() {return m_tasks;}

void Project::add_task(Task& task) {
    m_tasks.push_back(Task());
    std::string title = task.get_task_title();
    std::string description = task.get_task_description();
    std::string status = task.get_task_status();
    int id = task.get_task_id();

    m_tasks[m_tasks.size() - 1].set_task_title(title);
    m_tasks[m_tasks.size() - 1].set_task_description(description);
    m_tasks[m_tasks.size() - 1].set_task_status(status);
    m_tasks[m_tasks.size() - 1].set_task_id(id);
}

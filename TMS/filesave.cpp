#include "filesave.h"

#include <fstream>
#include <string>

#include <iostream>

FileSave::FileSave()
{}

void FileSave::save_users_file_txt(std::vector<User>& users) {
    std::ofstream fout;
    fout.open("../TMS/user_file_data.txt");

    fout << users.size() << "\n";
    for (auto i : users) {
        fout << i.get_user_name() << " ";
        fout << i.get_user_password() << " ";
        fout << i.get_user_id() << "\n";
    }
    fout << "(*)";
}

void FileSave::save_tasks_file_txt(std::vector<Task>& tasks, int user_id, int project_id) {
    std::string path = "../TMS/Tasks/task_" + std::to_string(user_id) + std::to_string(project_id) + ".txt";
    std::ofstream fout;
    int deleted_num = 0; // Tracker for deleted tasks/projects

    if (tasks.empty()) {
        return;
    }

    for (auto i : tasks) {
        if (i.get_task_status() == "Delete") {
            ++deleted_num;
        }
    }

    fout.open(path);
    fout << (tasks.size() - deleted_num) << "\n";
    deleted_num = 0;
    for (auto i : tasks) {
        if (i.get_task_status() == "Delete") {
            ++deleted_num;
            continue;
        }
        fout << i.get_task_title() << " ";
        fout << i.get_task_status() << " ";
        fout << (i.get_task_id() - deleted_num) << "\n";
        fout << "/-/\n";
        fout << i.get_task_description();
        if (i.get_task_description()[i.get_task_description().size() - 1] == '\n') {
            fout << "/-/\n\n";
        }
        else {
            fout << "\n/-/\n\n";
        }
    }
    fout << "(*)";
}

void FileSave::save_projects_file_txt(std::vector<Project>& projects, int user_id) {
    std::string path = "../TMS/Projects/project_" + std::to_string(user_id) + ".txt";
    std::ofstream fout;
    int deleted_num = 0; // Tracker for deleted tasks/projects

    if (projects.empty()) {
        return;
    }

    for (auto i : projects) {
        if (i.get_project_status() == "Delete") {
            ++deleted_num;
            std::ofstream delete_file_content;
            delete_file_content.open("../TMS/Tasks/task_" + std::to_string(user_id) + std::to_string(i.get_project_id()) + ".txt");
            delete_file_content << "(*)";
        }
    }

    fout.open(path);
    fout << (projects.size() - deleted_num) << "\n";
    deleted_num = 0;
    for (auto i : projects) {
        if (i.get_project_status() == "Delete") {
            ++deleted_num;
            continue;
        }
        fout << i.get_project_title() << " ";
        fout << i.get_project_status() << " ";
        fout << i.get_project_id() << "\n";
        fout << "/-/\n";
        fout << i.get_project_description();
        if (i.get_project_description()[i.get_project_description().size() - 1] == '\n') {
            fout << "/-/\n\n";
        }
        else {
            fout << "\n/-/\n\n";
        }
        std::vector<Task> tasks = i.get_project_tasks();
        save_tasks_file_txt(tasks, user_id, i.get_project_id());
    }
    fout << "(*)";
}

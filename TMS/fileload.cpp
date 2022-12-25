#include "fileload.h"

#include <string>
#include <fstream>
#include <QMessageBox>

#include <iostream>

FileLoad::FileLoad()
    : m_file_users{}
    , m_file_projects{}
{}

void FileLoad::check_users_file_txt(QWidget* parent) {
    std::ifstream fin;
    std::ofstream fout;

    fin.open("../TMS/user_file_data.txt");
    if (!fin.is_open()) {
        QMessageBox::information(parent, "User Message !", "No File 'user_file_data.txt' was found !\nNew File is created in TMS folder !");
        fout.open("../TMS/user_file_data.txt");
        fout << "0";
    }
    fin.close();
    fout.close();
}

std::vector<User> FileLoad::load_users_file_txt(QWidget* parent) {
    check_users_file_txt(parent);

    std::ifstream fin;
    std::string token;
    int count; // number of users
    int i = 0; // index for vector

    fin.open("../TMS/user_file_data.txt");
    if (!fin.is_open()) {
        QMessageBox::information(parent, "ERROR !", "Can't open the 'ser_file_data.txt' file, the program will be closed !");
        exit(0);
    }

    fin >> token;
    if (token == "(*)") {
        return {};
    }
    count = std::stoi(token);
    m_file_users.resize(count);

    while (!fin.eof()) {
        fin >> token;
        if (token == "(*)") {
            break;
        }

        m_file_users[i].set_user_name(token);
        fin >> token;
        m_file_users[i].set_user_password(token);
        fin >> token;
        m_file_users[i].set_user_id(std::stoi(token));
        ++i;
    }
    fin.close();

    return m_file_users;
}

std::vector<Project> FileLoad::load_projects_file_txt(QWidget* parent, int user_id) {
    std::ifstream fin;
    std::string token;
    std::string path = "../TMS/Projects/project_" + std::to_string(user_id) + ".txt"; // path finds user's projects by user's id
    int count; // number of projects
    int i = 0; // index for vector

    fin.open(path);
    if (!fin.is_open()) {
        return m_file_projects;
    }

    fin >> token;
    if (token == "(*)") {
        return {};
    }
    count = std::stoi(token);
    m_file_projects.resize(count);

    while (!fin.eof()) {
        fin >> token;
        if (token == "(*)") { // end of file
            break;
        }

        m_file_projects[i].set_project_title(token);
        fin >> token;
        m_file_projects[i].set_project_status(token);
        fin >> token;
        m_file_projects[i].set_project_id(std::stoi(token));
        fin >> token;
        if (token == "/-/") {
            std::getline(fin, token);
            std::string line; // line to add all description
            while (std::getline(fin, token)) {
                if (token == "/-/") {
                    break;
                }
                line += token + "\n";
            }
            m_file_projects[i].set_project_description(line);
        }
        else {
            QMessageBox::information(parent, "ERROR !", "PROJECT: " + QString::fromStdString(path) + " file format is wrong, the program will be closed !");
            exit(0);
        }
        ++i;
    }
    fin.close();

    return m_file_projects;
}

std::vector<Task> FileLoad::load_tasks_file_txt(QWidget* parent, int user_id, int project_id) {
    std::ifstream fin;
    std::string token;
    std::string path = "../TMS/Tasks/task_" + std::to_string(user_id) + std::to_string(project_id) + ".txt"; // path finds user's projects by user's id
    int count; // number of projects
    int i = 0; // index for vector

    fin.open(path);
    if (!fin.is_open()) {
        return {};
    }

    fin >> token;
    if (token == "(*)") {
        return {};
    }
    count = std::stoi(token);
    m_file_tasks.resize(count);

    while (!fin.eof()) {
        fin >> token;
        if (token == "(*)") { // end of file
            break;
        }

        m_file_tasks[i].set_task_title(token);
        fin >> token;
        m_file_tasks[i].set_task_status(token);
        fin >> token;
        m_file_tasks[i].set_task_id(std::stoi(token));
        fin >> token;
        if (token == "/-/") {
            std::getline(fin, token);
            std::string line; // line to add all description
            while (std::getline(fin, token)) {
                if (token == "/-/") {
                    break;
                }
                line += token + "\n";
            }
            m_file_tasks[i].set_task_description(line);
        }
        else {
            QMessageBox::information(parent, "ERROR !", "PROJECT: " + QString::fromStdString(path) + " file format is wrong, the program will be closed !");
            exit(0);
        }
        ++i;
    }
    fin.close();

    return m_file_tasks;
}

















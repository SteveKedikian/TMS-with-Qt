#include "user.h"

User::User()
    : m_username{}
    , m_password{}
    , m_id{}
{}

User::User( std::string& username, std::string& password, int id)
    : m_username{username}
    , m_password{password}
    , m_id{id}
{}

void User::set_user_name(std::string& username) {m_username = username;}

void User::set_user_password(std::string& password) {m_password = password;}

void User::set_user_id(int id) {m_id = id;}

std::string User::get_user_name() {return m_username;}

std::string User::get_user_password() {return m_password;}

int User::get_user_id() {return m_id;}

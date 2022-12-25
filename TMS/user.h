#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    User();
    User(std::string&, std::string&, int);

    void set_user_name(std::string&);
    void set_user_password(std::string&);
    void set_user_id(int);
    std::string get_user_name();
    std::string get_user_password();
    int get_user_id();

private:
    std::string m_username;
    std::string m_password;
    int m_id;
};

#endif // USER_H

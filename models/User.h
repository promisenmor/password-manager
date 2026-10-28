#ifndef USER_H
#define USER_H

#include<string>

using namespace std;

class User {
    public:
        std::string username;
        std::string password;

        User() {}
        User(std::string name, std::string password);
        virtual ~User() {}

        virtual bool isAdmin();

};

#endif


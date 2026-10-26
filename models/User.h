#ifndef USER_H
#define USER_H
#include<string>
using namespace std;

class User {
    public:
    string username;
    string password;
    bool isAdmin;

    User() : isAdmin(false) {}
    User(string u, string p, bool admin = false):
        username(u), password(p), isAdmin(admin) {}

};


#endif
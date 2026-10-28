#include "User.h"

User::User(string name, string password) {
    username = name;
    password = password;
}

bool User::isAdmin() {
    return false;
}


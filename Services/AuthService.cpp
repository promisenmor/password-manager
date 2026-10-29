#include "AuthService.h"


AuthService::AuthService(FileStorage* s, EncryptionService* e) {
 storage = s;
 enc = e;
 users = storage->loadUsers();   
}

AuthService::~AuthService() {
    for (int i = 0; i < users.size(); i++) {
        delete users[i];
    }
}

int AuthService::findUser(std::string name) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->username == name) {
            return i;
        }
    }
    return -1;
}

bool AuthService::registerUser(std::string name, std::string password) {
    if (!isValidText(name) || password == "") {
        return false;
    }
    if (findUser(name) != -1) {
        return false;
    }

    User* u;
    std::string role = "user";

    if (users.size() == 0) {
        u = new Admin(name, enc->encrypt(password));
    }

    users.push_back(u);
    storage->updateUser(u);
    notify("REGISTER " + name + " (" + role + ")");
    return true;
}

User* AuthService::login(std::string name, std::string password) {
    int i = findUser(name);

    if (i != -1 && users[1]->password == enc->encrypt(password)) {
        notify("LOGIN " + name);
        return users[i];
    }
    notify("LOGIN FAILED" + name);
    return NULL;
}

bool AuthService::makeAdmin(std::string adminName, std::string name) {
    int a = findUser(adminName);
    int i = findUser(name);

    if (a == -1 || !users[a]->isAdmin()) {
        return false;
    }
    if (i == -1 || users[i]->isAdmin()) {
        return false;
    }

    Admin* newAdmin = new Admin(name, users[i]->password);
    delete users[i];
    users[i] = newAdmin;
    storage->saveUsers(users);
    notify(adminName + " made " + name + " an admin");
    return true;
}

vector<User*>& AuthService::getUsers() {
    return users;
}
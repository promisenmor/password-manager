#include "FileStorage.h"
#include <fstream>
#include <cstdlib>

//Splits a line on '|' into parts[]. Returns how many parts were found
static int split(std::string line, std::string parts[], int max)
{
    int count = 0;

    while (count < max - 1) {
        int pos = line.find('|');
        if (pos == -1) {
            break;
        }
        parts[count] = line.substr(0, pos);
        line = line.substr(pos + 1);
        count++;
    }
    parts[count] = line;
    return count + 1;
}




FileStorage::FileStorage(std::string uFile, std::string cFile) {
    userFile = uFile;
    credFile = cFile;

    ofstream f1(userFile.c_str(), ios::app);
    ofstream f2(credFile.c_str(), ios::app);
}

string FileStorage::userLine(User* u) {
    string role = "user";
    if (u->isAdmin()) {
        role = "admin";
    }
    return u->username + "|" + u->password + "|" + role;
}

string FileStorage::credLine(Credential& c) {
    return c.owner + "|" + c.appName + "|" + c.type + "|" + c.loginUser
            + "|" + c.password + "|" + to_string(c.created) + "|" + to_string(c.updated);
}

vector<User*> FileStorage::loadUsers() {
    vector<User*> users;
    ifstream file(userFile.c_str());
    string line;
    string p[3];

    while (getline(file, line)) {
        if (line == "") {
            continue;
        }
        split(line, p, 3);
        if (p[2] == "admin") {
            users.push_back(new Admin(p[0], p[1]));
        }
        else {
            users.push_back(new User(p[0], p[1]));
        }
    }
    return users;
}

void FileStorage::saveUsers(vector<User*>& users) {
    ofstream file(userFile.c_str());

    for (int i = 0; i < users.size(); i++) {
        file << userLine(users[i]) << endl;
    }
}

void FileStorage::updateUser(User* u) {
    ofstream file(userFile.c_str(), ios::app);
    file << userLine(u) << endl;
}

vector<Credential> FileStorage::loadCredentials() {
    vector<Credential> list;
    ifstream file(credFile.c_str());
    std::string line;
    std::string p[7];

    while (getline(file, line)) {
        if (line == "") {
            continue;
        }
        split(line, p, 7);
        Credential c;
        c.owner = p[0];
        c.appName = p[1];
        c.type = p[2];
        c.loginUser = p[3];
        c.created = atol(p[5].c_str());
        c.updated = atol(p[6].c_str());
        list.push_back(c);
    }
    return list;
}


void FileStorage::saveCredentials(vector<Credential>& list) {
    ofstream file(credFile.c_str());

    for (int i = 0; i < list.size(); i++) {
        file << credLine(list[i]) << endl;
    }
}


void FileStorage::updateCredential(Credential& c) {
    ofstream file(credFile.c_str(), ios::app);
    file << credLine(c) << endl;
}


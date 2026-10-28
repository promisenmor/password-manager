#include "FileStorage.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>


FileStorage::FileStorage()
    : usersPath("data/users.txt"),
      credPath("data/credentials.txt"),
      auditPath("data/audit_log.txt") {
        ensureFile(usersPath);
        ensureFile(credPath);
        ensureFile(auditPath);
      }

void FileStorage::ensureFile(const string& path) {
    ofstream f(path, ios::app); // this creates a new file is no one exists before.
}

string FileStorage::now() {
    time_t t = time(nullptr);
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&t));
    return string(buf);
}

vector<User> FileStorage::loadUsers() {
    vector<User> users;
    ifstream f(usersPath);
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, u, p, a;
        getline(ss, id, '|');
        getline(ss, u, '|');
        getline(ss, p, '|');
        getline(ss, a, '|');
        users.push_back(User(u, p, a == "1"));

    }
    return users;
}

void FileStorage::saveUser(const User& user) {
    ofstream f(usersPath, ios::app);
    f << user.id << "|" << user.username << "|" << user.password << "|" << (user.isAdmin ? "1" : "0") << "\n";
}


void FileStorage::updateUser(const vector<User>& users) {
    ofstream f(usersPath);
    for (const User& user : users) {
        f << user.id << "|" << user.username << "|" << user.password << "|"
          << (user.isAdmin ? "1" : "0") << "\n";
    }
}

int FileStorage::nextUserId() {
    int mx = 0;
    for (auto& u : loadUsers()) mx = max(mx, user.id);
    return mx +1;
}


vector<Credential> FileStorage::loadCredentials() {
    vector<Credential> creds;
    ifstream f(credPath);
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Credential c;
        string id, oid
        getline(ss, c.owner, '|');
        getline(ss, c.appName, '|');
        getline(ss, c.username, '|');
        getline(ss, c.password, '|');
        getline(ss, c.dateCreated, '|');
        getline(ss, c.dateUpdated, '|');
        creds.push_back(c);
    }
    return creds;
}

void FileStorage::saveCredentials(const Credential& c) {
    ofstream f(credPath, ios::app);
    f << c.owner << "|" << c.appName << "|" << c.username << "|"
      << c.password << "|" << c.dateCreated << "|" << c.dateUpdated << "\n";
}

void FileStorage::updateCredentials(const vector<Credential>& creds) {
    ofstream f(credPath);
    for (const auto& c : creds)
        f << c.owner << "|" << c.appName << "|" << c.username << "|"
          << c.password << "|" << c.dateCreated << "|" << c.dateUpdated << "\n";
}

void FileStorage::logAudit(const string& action, const string& detail) {
    ofstream f(auditPath, ios::app);
    f << now() << "|" << action << "|" << detail << "\n";
}

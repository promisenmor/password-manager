#ifndef FILE_STORAGE_H
#define FILE_STORAGE_H
#include <iostream>


#include <string>
#include <vector>
#include "../models/User.h"
#include "../models/Credential.h"
using namespace std;


class FileStorage {
    private:
        string usersPath;
        string credPath;
        string auditPath;
        void ensureFile(const string& path);

    public:
        FileStorage();

        // for Users
        vector<User> loadUsers();
        void saveUser(const User& user);
        void updateUser(const vector<User>& user);

        // for credentials
        vector<Credential> loadCredentials();
        void saveCredentials(const Credential& cred);
        void updateCredentials(const vector<Credential>& creds);
        void deleteCredentials(const string& owner, const string& app);

        // for audit 
        void logAudit(const string& action, const string& detail);

        static string now();

};


#endif
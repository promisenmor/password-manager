#ifndef FILE_STORAGE_H
#define FILE_STORAGE_H


#include <string>
#include <vector>
#include "../models/User.h"
#include "../models/Credential.h"
#include "../services/AuditObserver.h"
using namespace std;

class FileStorage : public AuditObserver {
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
        int nextUserId();

        // for credentials
        vector<Credential> loadCredentials();
        void saveCredentials(const Credential& cred);
        void updateCredentials(const vector<Credential>& creds);
        void deleteCredentials(const string& owner, const string& app);
        int nextCredentialId();

        // for audit 
        void logAudit(const string& action, const string& detail);
        void printAuditLog();
        void onEvent(const string& action, const string& detail) {
            logAudit(action, detail); }
        }


        static string now();

};


#endif
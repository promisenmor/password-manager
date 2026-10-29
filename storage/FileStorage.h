#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <string>
#include <vector>
#include "../models/admin.h"
#include "../models/credential.h"


class FileStorage {
    private:
        string userFile;
        string credFile;
        string userLine(User* u);
        string credLine(Credential& c);

    public:
        FileStorage(string uFile = "data/users.txt", 
                    std::string cFile = "data/credentials.txt"); 
                    
        vector<User*> loadUsers();
        void saveUsers(vector<User*>& users);
        void updateUser(User* u);

        vector<Credential> loadCredentials();
        void saveCredentials(vector<Credential>& list);
        void updateCredential(Credential& c);
};


#endif
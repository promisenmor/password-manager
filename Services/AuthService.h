#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include "Subject.h"
#include "Validation.h"
#include "EncryptionService.h"
#include "../storage/FileStorage.h"


class AuthService : public Subject {
    private:
        FileStorage* storage;
        EncryptionService* enc;
        vector<User*> users;

        int findUser(string name);

    public:
        AuthService(FileStorage* s, EncryptionService*);
        ~AuthService();

        bool registerUser(std::string name, std::string password);

        User* login(std::string name, std::string password);

        bool makeAdmin(std::string adminName, std::string name);
        vector<User*>& getUsers();
};

#endif
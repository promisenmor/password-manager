#ifndef CREDENTIALSERVICE_H
#define CREDENTIALSERVICE_H

#include "Subject.h"
#include "Validation.h"
#include "EncryptionService.h"
#include "../storage/FileStorage.h"


class CredentialService : public Subject {
    private:
        FileStorage* storage;
        EncryptionService* enc;
        vector<Credential> items;

        int findIndex(std::string owner, std::string name);

    public:
    CredentialService(FileStorage* s, EncryptionService* e);
    bool add(std::string owner, std::string appName, std::string type, 
                      std::string loginUser, std::string password)
    bool edit(std::string owner, std::string appName, std::string newappName, 
                std::string type, 
                      std::string loginUser, std::string password);
};

#endif
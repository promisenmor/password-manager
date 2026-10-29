#ifndef ENCRYPTION_SERVICE_H
#define ENCRYPTION_SERVICE_H

#include <string>
using namespace std;

class EncryptionService {
    private:
        std::string key;

    public:
        EncryptionService() { key = "SecretKey"; }

        std::string encrypt(std::string text);
        std::string decrypt(std::string hex);

};



#endif 
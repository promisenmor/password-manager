#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <string>
#include <ctime>

using namespace std;

class Credential {
    public:
        std::string owner;
        std::string appName;
        std::string type;
        std::string loginUser;
        std::string password;
        time_t created;
        time_t updated;

        Credential() {created = 0; updated = 0; }
        Credential(std::string o, std::string a, std::string t, std::string login, std::string pass);

        void update(std::string a, std::string t, std::string login, std::string pass);
        std::string createdText();
        std::string updatedText();
};


#endif
#ifndef CREDENTIAL_H
#define CREDENTIAL_H
#include <string>
using namespace std;

class Credential {
public:
    string owner;
    string appName;
    string username;
    string password;
    string dateCreated;
    string dateUpdated;

    Credential() {}
    Credential(string o, string app, string user, string password, 
                string created, string updated = "")
        : owner(o), appName(app), username(user), password(password),
          dateCreated(created), dateUpdated(updated.empty() ? created : updated) {}


};

#endif


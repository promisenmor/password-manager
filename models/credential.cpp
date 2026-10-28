#include "credential.h"

static std::string timeText(time_t t) {
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", localtime(&t));

    return buf;
}


Credential::Credential(std::string o, std::string a, std::string t, std::string login, std::string password) {
    owner = o;
    appName = a;
    type = t;
    loginUser = login;
    password = password;
    created = time(NULL);
    updated = created;
}


void Credential::update(std::string a, std::string t, std::string login, std::string pass) {
    appName = a;
    type = t;
    loginUser = login;
    password = password;
    updated = time(NULL);
}

string Credential::createdText() {
    return timeText(created);
}


string Credential::updatedText() {
    return timeText(updated);
}
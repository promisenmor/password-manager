#ifndef ENCRYPTION_SERVICE_H
#define ENCRYPTION_SERVICE_H

#include <string>
using namespace std;

class EncryptionService {
    public:
    static const char KEY = 'k';
    static string encrypt(const string& text);
    static string decrypt(const string& text);
};

#endif // ENCRYPTION_SERVICE_H
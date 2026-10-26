#include "EncryptionService.h"

string EncryptionService::encrypt(const string& text) {
    string result = text;
    for (char& c : result) c ^= KEY;
    return result;
}

string EncryptionService::decrypt(const string& text) {
    return encrypt(text);
}
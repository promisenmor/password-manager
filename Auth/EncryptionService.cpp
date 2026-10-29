#include "EncryptionService.h"

static int hexValue(char c) {
    if (c >= '0' && c <= '9' ) {
        return c - '0';
    }
    return c - 'a' + 10;
}

//Encryption with the XOR operator(^)
string EncryptionService::encrypt(std::string text) {
    std::string digits = "0123456789abcdef";
    std::string result = "";

    for ( int i = 0; i < text.length(); i++) {
        unsigned char c = text[i] ^ key[i % key.length()];

        result += digits[c / 16];
        result += digits[c % 16];

    }
    return result;
}


// Decryption
string EncryptionService::decrypt(std::string hex) {
    std::string result = "";

    for (int i = 0; i + 1 < hex.length(); i += 2) {
        int c = hexValue(hex[i]) * 16 + hexValue(hex[i + 1]);
        result += (char)(c ^ key[(i /2) % key.length()]);
    }
    return result;
}

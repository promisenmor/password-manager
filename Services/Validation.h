#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
using namespace std;

// this code is to reject any use of "|" because is a field seprator in the text file, so it can be used in the program.
inline bool isValidText(std::string s) {
    return s != "" && s.find('|') == string::npos;
}


#endif
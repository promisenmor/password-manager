#include "AuditService.h"
#include <fstream>
#include <ctime>


AuditService::AuditService(std::string file) {
    logFile = file;
    ofstream f(logFile.c_str(), ios::app);
}

void AuditService::update(std::string message) {
    char buf[20];
    time_t now = time(NULL);
    strftime(buf, sizeof(buf), "%Y-%m_%d %H:%M", localtime(&now));

    ofstream file(logFile.c_str(), ios::app);
    file << buf << " | " << message << endl;
}

vector<string> AuditService::readLog() {
    vector<string> lines;
    ifstream file(logFile.c_str());
    std::string line;

    while (getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}
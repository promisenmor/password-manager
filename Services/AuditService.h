#ifndef AUDITSERVICE_H
#define AUDITSERVICE_H

#include <vector>
#include <string>
#include "AuditObserver.h"

class  AuditService : public AuditObserver {
    private:
        std::string logFile;
    
    public:
        AuditService(std::string file = "data/audit_log.txt");

        void update(std::string message);
        std::vector<std::string> readLog();
        
};

#endif
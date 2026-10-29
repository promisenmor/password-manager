#ifndef AUDIT_OBSERVER_H
#define AUDIT_OBSERVER_H

#include <string>

using namespace std;

class AuditObserver {
    public:
        virtual ~AuditObserver() {}
        virtual void update(string message) = 0;
        
};

#endif
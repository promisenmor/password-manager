#ifndef AUDIT_OBSERVER_H
#define AUDIT_OBSERVER_H
#include <string>

using namespace std;

class AuditObserver {
    public:
        virtual ~AuditObserver() {}
        virtual void onEvent(const string& action, const string& detail) = 0;
        
};

#endif
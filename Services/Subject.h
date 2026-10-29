#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "AuditObserver.h"


class Subject {
    private:
        vector <AuditObserver*> observers;

    public:
        void attach(AuditObserver* o) {
            observers.push_back(o);
        }

        void notify(string message) {
            for (int i = 0; i < observers.size(); i++) {
                observers[i]->update(message);
            }
        }
};

#endif
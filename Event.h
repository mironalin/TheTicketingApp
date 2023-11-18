//
// Created by alinm on 11/17/2023.
//

#ifndef THETICKETINGAPP_EVENT_H
#define THETICKETINGAPP_EVENT_H

#include <iostream>

class Event {
private:
    char* eventName;
    char* eventDate;
    char* eventTime;

public:

    // Accessors
    const char* getEventName() const;
    const char* getEventDate() const;
    const char* getEventTime() const;

};

#endif //THETICKETINGAPP_EVENT_H

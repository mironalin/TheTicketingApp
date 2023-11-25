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
    // Default constructor
    Event();
    Event(const char* name, const char* date, const char* time);

    // Destructor
    ~Event();

    // Copy constructor
    Event(const Event& other);

    // Accessors
    const char* getEventName() const;
    const char* getEventDate() const;
    const char* getEventTime() const;

    // Setters with validations
    void setEventName(const char* name);
    void setEventDate(const char* date);
    void setEventTime(const char* time);

    // Display details method
    void displayEventDetails() const;
};

#endif //THETICKETINGAPP_EVENT_H

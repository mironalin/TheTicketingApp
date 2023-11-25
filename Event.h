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

    // Copy assignment operator
    Event& operator=(const Event& other);

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

    // Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Event& event);
    friend std::istream& operator>>(std::istream& is, Event& event);
};

#endif //THETICKETINGAPP_EVENT_H

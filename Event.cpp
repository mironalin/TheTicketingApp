#include "Event.h"
#include <iostream>
#include <cstring>

// Accessors
const char* Event::getEventName() const {
    return eventName;
}

const char* Event::getEventDate() const {
    return eventDate;
}

const char* Event::getEventTime() const {
    return eventTime;
}

// Setters with validations
void Event::setEventName(const char* name) {
    // Validate the input (name should not be empty)
    if (name == nullptr || strlen(name) == 0) {
        std::cerr << "Invalid event name. Please provide a non-empty name.\n";
        return;
    }

    // Free existing memory
    delete[] eventName;

    // Allocate memory for eventName and copy the input string
    eventName = new char[strlen(name) + 1];
    strcpy(eventName, name);
}

void Event::setEventDate(const char* date) {
    // Validate the input (date should not be empty)
    if (date == nullptr || strlen(date) == 0) {
        std::cerr << "Invalid event date. Please provide a non-empty date.\n";
        return;
    }

    // Free existing memory
    delete[] eventDate;

    // Allocate memory for eventDate and copy the input string
    eventDate = new char[strlen(date) + 1];
    strcpy(eventDate, date);
}

void Event::setEventTime(const char* time) {
    // Validate the input (time should not be empty)
    if (time == nullptr || strlen(time) == 0) {
        std::cerr << "Invalid event time. Please provide a non-empty time.\n";
        return;
    }

    // Free existing memory
    delete[] eventTime;

    // Allocate memory for eventTime and copy the input string
    eventTime = new char[strlen(time) + 1];
    strcpy(eventTime, time);
}


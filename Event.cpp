#include "Event.h"
#include <iostream>
#include <cstring>

// Default constructor
Event::Event() : eventName(nullptr), eventDate(nullptr), eventTime(nullptr) {}

// Parameterized constructor
Event::Event(const char* name, const char* date, const char* time) {
    // Allocate memory for eventName, eventDate, and eventTime and copy the input strings
    eventName = new char[strlen(name) + 1];
    strcpy(eventName, name);

    eventDate = new char[strlen(date) + 1];
    strcpy(eventDate, date);

    eventTime = new char[strlen(time) + 1];
    strcpy(eventTime, time);
}

// Destructor
Event::~Event() {
    delete[] eventName;
    delete[] eventDate;
    delete[] eventTime;
}

// Copy constructor
Event::Event(const Event &other) {
    // Allocate memory for eventName, eventDate, and eventTime and copy from the other object
    eventName = new char[strlen(other.eventName) + 1];
    strcpy(eventName, other.eventName);

    eventDate = new char[strlen(other.eventDate) + 1];
    strcpy(eventDate, other.eventDate);

    eventTime = new char[strlen(other.eventTime) + 1];
    strcpy(eventTime, other.eventTime);
}

// Copy assignment operator
Event& Event::operator=(const Event& other) {
    if(this != &other) {
        // Free existing memory
        delete[] eventName;
        delete[] eventDate;
        delete[] eventTime;

        // Copy values from the other object
        eventName = new char[strlen(other.eventName) + 1];
        strcpy(eventName, other.eventName);

        eventDate = new char[strlen(other.eventDate) + 1];
        strcpy(eventDate, other.eventDate);

        eventTime = new char[strlen(other.eventTime) + 1];
        strcpy(eventDate, other.eventDate);
    }
    return *this;
}

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

// Display details method
void Event::displayEventDetails() const {
    std::cout << "\n========== Event details ==========\n";
    std::cout << "Event Name: " << eventName << "\n";
    std::cout << "Event Date: " << eventDate << "\n";
    std::cout << "Event Time: " << eventTime << "\n";
    std::cout << "========== Event details ==========\n\n";
}

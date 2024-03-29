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

    // Function to check if a date is valid
    bool isValidDate(const char* date);

    // Function to check if a time is valid
    bool isValidTime(const char* time);

    // Accessors
    [[nodiscard]] const char* getEventName() const;
    [[nodiscard]] const char* getEventDate() const;
    [[nodiscard]] const char* getEventTime() const;

    // Setters with validations
    void setEventName(const char* name);
    void setEventDate(const char* date);
    void setEventTime(const char* time);

    // Display details method
    void displayEventDetails() const;

    // Input method for file processing
    void readFromFile(std::istream& is);

    // Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Event& event);
    friend std::istream& operator>>(std::istream& is, Event& event);
};

#endif //THETICKETINGAPP_EVENT_H
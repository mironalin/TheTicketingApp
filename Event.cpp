#include "Event.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <string>
#include <cctype>

// Default constructor
Event::Event() : eventName(nullptr), eventDate(nullptr), eventTime(nullptr) {}

// Parameterized constructor with validations
Event::Event(const char* name, const char* date, const char* time) {
    // Allocate memory for eventName, eventDate, and eventTime and copy the input strings
    if (name == nullptr || strlen(name) == 0) {
        std::cerr << "\nInvalid event name. Please provide a non-empty name.\n";
        eventName = nullptr;
    } else {
        eventName = new char[strlen(name) + 1];
        strcpy(eventName, name);
    }

    if (date == nullptr || strlen(date) == 0) {
        std::cerr << "\nInvalid event date. Please provide a non-empty date.\n";
        eventDate = nullptr;
    } else {
        eventDate = new char[strlen(date) + 1];
        strcpy(eventDate, date);
    }

    if (time == nullptr || strlen(time) == 0) {
        std::cerr << "\nInvalid event time. Please provide a non-empty time.\n";
        eventTime = nullptr;
    } else {
        eventTime = new char[strlen(time) + 1];
        strcpy(eventTime, time);
    }
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

// Function to check if the date is valid
bool Event::isValidDate(const char* date) {
    // Check length for format DD.MM.YYYY
    if (strlen(date) != 10) return false;
    // Check for dots at the correct positions
    if (date[2] != '.' || date[5] != '.') return false;

    // Extract day, month, and year
    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');

    // Basic checks for year, month, and day
    if (year < 1000 || year > 9999) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false; // This is a simplified check and doesn't account for different days in each month

    return true;
}

// Function to check if the time is valid
bool Event::isValidTime(const char* time) {
    // Check length for format HH:MM
    if (strlen(time) != 5) return false;
    // Check for colon at the correct position
    if (time[2] != ':') return false;

    // Extract hour and minute
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');

    // Basic checks for hour and minute
    if (hour < 0 || hour > 23) return false;
    if (minute < 0 || minute > 59) return false;

    return true;
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
        std::cerr << "\nInvalid event name. Please provide a non-empty name.";
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
        std::cerr << "\nInvalid event date. Please provide a date in DD.MM.YYYY format.";
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
        std::cerr << "\nInvalid event time. Please provide a time in HH:MM format.";
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

/*
// Input method for file processing
void Event::readFromFile(std::istream& is) {
    // Read data directly without prompts
    // Assuming eventName, eventDate, eventTime are std::strings for simplicity
    std::string eventName, eventDate, eventTime;
    is >> eventName;
    is >> eventDate;
    is >> eventTime;
    setEventName(eventName.c_str());
    setEventDate(eventDate.c_str());
    setEventTime(eventTime.c_str());
}
*/

void Event::readFromFile(std::istream& is) {
    std::string eventName, eventDate, eventTime;

    // Read Event Name
    std::getline(is, eventName);
    if (eventName.empty() || std::any_of(eventName.begin(), eventName.end(), ::isdigit)) {
        std::cerr << "\nInvalid event name in file. It should not be empty and should not contain digits.";
        return; // Abort reading process
    }
    setEventName(eventName.c_str());

    // Read Event Date
    std::getline(is, eventDate);
    if (!isValidDate(eventDate.c_str())) {
        std::cerr << "\nInvalid event date in file. It should be in DD.MM.YYYY format.";
        return; // Abort reading process
    }
    setEventDate(eventDate.c_str());

    // Read Event Time
    std::getline(is, eventTime);
    if (!isValidTime(eventTime.c_str())) {
        std::cerr << "\nInvalid event time in file. It should be in HH:MM format.";
        return; // Abort reading process
    }
    setEventTime(eventTime.c_str());
}


// Operator overloads
std::ostream& operator<<(std::ostream& os, const Event& event) {
    os << event.eventName << " - Date: " << event.eventDate << ", Time: " << event.eventTime;
    return os;
}

std::istream& operator>>(std::istream& is, Event& event) {

    std::cout << "\n========== Enter Event Details ==========\n";

    std::cout << "\nEnter Event Name: ";
    std::string name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
    std::getline(is, name);
    // Validate the input (name should not be empty and should not contain digits)
    while (name.empty() || std::any_of(name.begin(), name.end(), ::isdigit)) {
        std::cerr << "\nEvent Name should not be empty and should not contain digits. Please enter a valid name: ";
        std::getline(is, name);
    }
    event.setEventName(name.c_str());

    std::cout << "\nEnter Event Date (DD.MM.YYYY): ";
    std::string date;
    std::getline(is, date);
    // Validate the input
    while (!event.isValidDate(date.c_str())) {
        std::cerr << "\nEvent Date should not be empty and should be in DD.MM.YYYY format. Please enter a valid date (DD.MM.YYYY): ";
        std::getline(is, date);
    }
    event.setEventDate(date.c_str());

    std::cout << "\nEnter Event Time (HH:MM): ";
    std::string time;
    std::getline(is, time);
    // Validate the input
    while (!event.isValidTime(time.c_str())) {
        std::cerr << "\nEvent Time should not be empty and should be in HH:MM format. Please enter a valid time (HH:MM): ";
        std::getline(is, time);
    }
    event.setEventTime(time.c_str());

    std::cout << "\n========== Event Details Entered ==========\n\n";

    return is;
}
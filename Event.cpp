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



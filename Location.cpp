#include "Location.h"
#include <iostream>
#include <cstring>

// Accessors
const char* Location::getLocationName() const {
    return name;
}

int Location::getMaxSeats() const {
    return maxSeats;
}

int Location::getNumRows() const {
    return numRows;
}

int Location::getNumZones() const {
    return numZones;
}

const int* Location::getZoneCapacities() const {
    return zoneCapacities;
}



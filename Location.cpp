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

// Setters with validations
void Location::setLocationName(const char* n) {
    // Validate the input (name should not be empty)
    if (strlen(n) > 0) {
        // Free existing memory
        delete[] name;

        // Allocate memory for name and copy the input string
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    } else {
        std::cerr << "Invalid input for Location Name. Please provide a non-empty name.\n";
    }
}

void Location::setMaxSeats(int max) {
    // Validate the input (max seats should be a positive value)
    if (max > 0) {
        maxSeats = max;
    } else {
        std::cerr << "Invalid input for Maximum Seats. Please provide a positive value.\n";
    }
}

void Location::setNumRows(int rows) {
    // Validate the input (number of rows should be a positive value)
    if (rows > 0) {
        numRows = rows;
    } else {
        std::cerr << "Invalid input for Number of Rows. Please provide a positive value.\n";
    }
}

void Location::setNumZones(int zones) {
    // Validate the input (number of zones should be a positive value)
    if (zones > 0) {
        numZones = zones;
    } else {
        std::cerr << "Invalid input for Number of Zones. Please provide a positive value.\n";
    }
}

void Location::setZoneCapacities(int* capacities) {
    // Validate the input (capacities should not be null)
    if (capacities != nullptr) {
        // Free existing memory
        delete[] zoneCapacities;

        // Allocate memory for zoneCapacities and copy values
        zoneCapacities = new int[numZones];
        for (int i = 0; i < numZones; ++i) {
            zoneCapacities[i] = capacities[i];
        }
    } else {
        std::cerr << "Invalid input for Zone Capacities. Please provide a non-null array.\n";
    }
}



#include "Location.h"
#include <iostream>
#include <cstring>

// Default constructor
Location::Location() : name(nullptr), maxSeats(0), numRows(0), numZones(0), zoneCapacities(nullptr) {}

// Parameterized constructor
Location::Location(const char* n, int max, int rows, int zones, int* capacities) : maxSeats(max), numRows(rows), numZones(zones) {
    // Allocate memory for name and copy the input string
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    // Allocate memory for zoneCapacities and copy values
    zoneCapacities = new int[numZones];
    for (int i = 0; i < numZones; ++i) {
        zoneCapacities[i] = capacities[i];
    }
}

// Destructor
Location::~Location() {
    delete[] name;
    delete[] zoneCapacities;
}

// Copy constructor
Location::Location(const Location &other) : maxSeats(other.maxSeats), numRows(other.numRows), numZones(other.numZones) {
    // Allocate memory for name and copy from the other object
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    // Allocate memory for zoneCapacities and copy values
    zoneCapacities = new int[numZones];
    for(int i = 0; i < numZones; ++i) {
        zoneCapacities[i] = other.zoneCapacities[i];
    }
}

// Copy assignment operator
Location& Location::operator=(const Location &other) {
    if(this != &other) {
        // Free existing memory
        delete[] name;
        delete[] zoneCapacities;

        // Copy values from the other object
        maxSeats = other.maxSeats;
        numRows = other.numRows;
        numZones = numZones;

        // Allocate memory for name and copy from the other object
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        // Allocate memory for zoneCapacities and copy values
        zoneCapacities = new int[numZones];
        for(int i = 0; i < numZones; ++i) {
            zoneCapacities[i] = other.zoneCapacities[i];
        }
    }
    return *this;
}

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

// Display details method
void Location::displayLocationDetails() const {
    std::cout << "\n========== Location Details ==========\n";
    std::cout << "Location Name: " << name << "\n";
    std::cout << "Maximum seats: " << maxSeats << "\n";
    std::cout << "Number of rows: " << numRows << "\n";
    std::cout << "Number of zones: " << numZones << "\n";
    std::cout << "Zone Capacities: ";
    for(int i = 0; i < numZones; ++i) {
        std::cout << zoneCapacities[i] << " ";
    }
    std::cout << "\n========== Location Details ==========\n\n";
}

// Operator overloads
std::ostream& operator<<(std::ostream& os, const Location& location) {
    os << location.name << " " << location.maxSeats << " "  << location.numRows << " " << location.numZones;
    for(int i = 0; i < location.numZones; ++i) {
        os << " " << location.zoneCapacities[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, Location& location) {
    std::cout << "\n========== Enter Location Details ==========\n";
    std::cout << "Name: ";
    std::string name;
    is >> name;
    location.setLocationName(name.c_str());

    std::cout << "Maximum Seats: ";
    int maxSeats;
    is >> maxSeats;
    location.setMaxSeats(maxSeats);

    std::cout << "Number of Rows: ";
    int numRows;
    is >> numRows;
    location.setNumRows(numRows);

    std::cout << "Number of Zones: ";
    int numZones;
    is >> numZones;
    location.setNumZones(numZones);

    // Allocate memory for zoneCapacities array and read values
    int* zoneCapacities = new int[numZones];
    for(int i = 0; i < numZones; ++i) {
        std::cout << "Capacity for Zone " << (i+1) << ": ";
        is >> zoneCapacities[i];
    }
    location.setZoneCapacities(zoneCapacities);
    delete[] zoneCapacities;

    std::cout << "\n========== Location Details Entered\n\n";
    return is;
}

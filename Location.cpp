#include "Location.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <sstream>

// Default constructor
Location::Location() : name(nullptr), maxSeats(0), numRows(0), numZones(0), zoneCapacities(nullptr) {}

// Parameterized constructor
Location::Location(const char* n, int max, int rows, int zones, int* capacities) : maxSeats(max), numRows(rows), numZones(zones) {
    // Allocate memory for name and copy the input string
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    // Allocate memory for zoneCapacities and copy values and validate
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

// Input method for file processing
void Location::readFromFile(std::istream& is) {
    std::string line;

    // Read Location Name
    std::getline(is, line);
    if (line.empty() || std::any_of(line.begin(), line.end(), ::isdigit)) {
        std::cerr << "\nInvalid Location Name (should not be empty or contain digits)";
        return;
    }
    setLocationName(line.c_str());

    // Read maxSeats
    if (!std::getline(is, line) || !(std::stringstream(line) >> maxSeats) || maxSeats <= 0) {
        std::cerr << "\nInvalid value for the number of maximum seats";
        return;
    }

    // Read numRows
    if (!std::getline(is, line) || !(std::stringstream(line) >> numRows) || numRows <= 0) {
        std::cerr << "\nInvalid value for the number of rows";
        return;
    }

    // Read numZones
    if (!std::getline(is, line) || !(std::stringstream(line) >> numZones) || numZones <= 0) {
        std::cerr << "\nInvalid value for the number of zones";
        return;
    }

    // Read Zone Capacities
    zoneCapacities = new int[numZones];
    for (int i = 0; i < numZones; ++i) {
        if (!std::getline(is, line) || !(std::stringstream(line) >> zoneCapacities[i]) || zoneCapacities[i] <= 0) {
            std::cerr << "\nInvalid value for Zone Capacities";
            delete[] zoneCapacities; // Clean up to avoid memory leaks
            return;
        }
    }
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

    std::cout << "\nEnter Location Name: ";
    std::string name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
    std::getline(is, name);

    // Validate the input (name should not be empty and should not contain digits)
    while (name.empty() || std::any_of(name.begin(), name.end(), ::isdigit)) {
        std::cerr << "\nLocation Name should not be empty and should not contain digits. Please enter a valid name: ";
        std::getline(is, name);
    }
    location.setLocationName(name.c_str());

    std::cout << "\nEnter Maximum Seats: ";
    int maxSeats;
    // Validate the input (max seats should be a positive value) and should not contain characters
    while (true) {
        if (!(is >> maxSeats)) {
            std::cerr << "\nInvalid input. Please enter a positive integer for maximum seats: ";
            is.clear(); // Clear the error state
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        } else if (maxSeats <= 0) {
            std::cerr << "\nMaximum seats should be a positive value. Please enter a valid value: ";
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        } else {
            break;
        }
    }
    location.setMaxSeats(maxSeats);

    std::cout << "\nEnter Number of Rows: ";
    int numRows;
    // Validate the input (number of rows should be a positive value) and should not contain characters
    while (true) {
        if (!(is >> numRows)) {
            std::cerr << "\nInvalid input. Please enter a positive integer for the number of rows: ";
            is.clear(); // Clear the error state
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        } else if (numRows <= 0) {
            std::cerr << "\nNumber of rows should be a positive value. Please enter a valid value: ";
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        } else {
            break;
        }
    }
    location.setNumRows(numRows);

    std::cout << "\nEnter Number of Zones: ";
    int numZones;
    // Validate the input (number of zones should be a positive value) and should not contain characters
    while (true) {
        if (!(is >> numZones)) {
            std::cerr << "\nInvalid input. Please enter a positive integer for the number of zones: ";
            is.clear(); // Clear the error state
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        } else if (numZones <= 0) {
            std::cerr << "\nNumber of zones should be a positive value. Please enter a valid value: ";
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        } else {
            break;
        }
    }
    location.setNumZones(numZones);

    // Allocate memory for zoneCapacities array and read values
    int* zoneCapacities = new int[numZones];
    for (int i = 0; i < numZones; ++i) {
        std::cout << "\nCapacity for Zone " << (i + 1) << ": ";
        while (!(is >> zoneCapacities[i]) || zoneCapacities[i] <= 0) {
            std::cerr << "\nInvalid input for zone capacity. Please enter a positive integer: ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    location.setZoneCapacities(zoneCapacities);
    delete[] zoneCapacities;

    std::cout << "\n========== Location Details Entered ==========\n" << std::endl;
    return is;
}

// Deprecated method
void Location::decrementZoneCapacity(int zoneIndex) {
    if (zoneIndex >= 0 && zoneIndex < numZones) {
        --zoneCapacities[zoneIndex];
    }
}

// New method to initialize seat layout
void Location::initializeSeats() {
    seats.resize(numZones);
    for (int z = 0; z < numZones; ++z) {
        seats[z].resize(numRows);
        for (int r = 0; r < numRows; ++r) {
            seats[z][r].resize(zoneCapacities[z] / numRows, true); // Assuming equal distribution of seats per row
        }
    }
}

// New method to find the first available seat
std::pair<int, int> Location::findAvailableSeat(int zone, int row) {
    // Subtract 1 to convert to 0-based indexing
    zone--;
    row--;
    for (size_t seat = 0; seat < seats[zone][row].size(); ++seat) {
        if (seats[zone][row][seat]) {
            return {row + 1, seat + 1}; // Convert back to 1-based indexing for user
        }
    }
    return {-1, -1}; // Indicate no available seat
}

// New method to allocate a seat
void Location::allocateSeat(int zone, int row, int seatNumber) {
    // Subtract 1 to convert to 0-based indexing
    zone--;
    row--;
    seatNumber--;
    if (zone >= 0 && zone < numZones && row >= 0 && row < numRows && seatNumber >= 0 && seatNumber < seats[zone][row].size()) {
        seats[zone][row][seatNumber] = false;
    }
}




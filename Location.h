#ifndef THETICKETINGAPP_LOCATION_H
#define THETICKETINGAPP_LOCATION_H

#include <iostream>
#include <vector>

class Location {
private:
    char* name;
    int maxSeats;
    int numRows;
    int numZones;
    int* zoneCapacities;

public:
    // Default constructor
    Location();
    Location(const char* n, int max, int rows, int zones, int* capacities);

    // Destructor
    ~Location();

    // Copy constructor
    Location(const Location& other);

    // Copy assignment operator
    Location& operator=(const Location& other);

    // Accessors
    const char* getLocationName() const;
    int getMaxSeats() const;
    int getNumRows() const;
    int getNumZones() const;
    const int* getZoneCapacities() const;

    // Setters with validations
    void setLocationName(const char* n);
    void setMaxSeats(int max);
    void setNumRows(int rows);
    void setNumZones(int zones);
    void setZoneCapacities(int* capacities);

    // Display details method
    void displayLocationDetails() const;

    // Input method for file processing
    void readFromFile(std::istream& is);

    // Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Location& location);
    friend std::istream& operator>>(std::istream& is, Location& location);

    void decrementZoneCapacity(int zoneIndex);
};

#endif //THETICKETINGAPP_LOCATION_H

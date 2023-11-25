//
// Created by alinm on 11/17/2023.
//

#ifndef THETICKETINGAPP_LOCATION_H
#define THETICKETINGAPP_LOCATION_H

#include <iostream>

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

};

#endif //THETICKETINGAPP_LOCATION_H

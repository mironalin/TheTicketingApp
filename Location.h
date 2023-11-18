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
    
    // Accessors
    const char* getLocationName() const;
    int getMaxSeats() const;
    int getNumRows() const;
    int getNumZones() const;
    const int* getZoneCapacities() const;

};

#endif //THETICKETINGAPP_LOCATION_H

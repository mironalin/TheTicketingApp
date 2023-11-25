#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>

int main() {
    // Initialize Location and Event
    Location location;
    Event event;

    // User input for Location
    std::cin >> location;

    // User input for Event
    std::cin >> event;

    //Display Location details
    std::cout << "\nLocation Details:\n";
    location.displayLocationDetails();

    //Display Event details
    std::cout << "\nEvent Details:\n";
    event.displayEventDetails();

    return 0;
}

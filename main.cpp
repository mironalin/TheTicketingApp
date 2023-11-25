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

    // Display Location details
    std::cout << "\nLocation Details:\n";
    location.displayLocationDetails();

    // Display Event details
    std::cout << "\nEvent Details:\n";
    event.displayEventDetails();

    // Menu-driven options
    int choice;
    do {
        std::cout << "\n========== MENU ==========";
        std::cout << "\n1. Generate Ticket \n";
        std::cout << "\n2. Validate Ticket \n";
        std::cout << "\n3. Exit \n";
        std::cout << "========== MENU ==========\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;


    } while (choice != 3);

    return 0;
}

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

        switch (choice) {
            case 1: {
                // Generate Ticket
                Ticket generatedTicket("Normal");
                generatedTicket.generateTicketId();
                generatedTicket.displayTicketDetails();
                break;
            }
            case 2: {
                // Validate Ticket
                int ticketId;
                std::cout << "\nEnter Ticket ID to validate: ";
                std::cin >> ticketId;

                // Access the static member using public static member function
                if(ticketId >= Ticket::getUniqueIdCounter() - 10 && ticketId <= Ticket::getUniqueIdCounter()) {
                    std::cout << "Ticket is valid. \n";
                } else {
                    std::cout << "Ticket is not valid.\n";
                }
                break;
            }
            case 3: {
                std::cout << "\nExiting the program. \n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 3);

    return 0;
}

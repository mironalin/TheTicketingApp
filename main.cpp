#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>
#include <fstream>
#include <string>

// Function for file processing using command line arguments
void processFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    Location location;
    Event event;

    // Process Location and Event from file
    location.readFromFile(file);
    event.readFromFile(file);

    // Display details
    location.displayLocationDetails();
    event.displayEventDetails();

    // Process Tickets from file
    int ticketChoice;
    while (file >> ticketChoice) {
        switch (ticketChoice) {
            case 1: {
                Ticket generatedTicket("Normal");
                generatedTicket.generateTicketId();
                generatedTicket.displayTicketDetails();
                break;
            }
            case 2: {
                int ticketId;
                file >> ticketId;
                if(ticketId >= Ticket::getUniqueIdCounter() - 10 && ticketId <= Ticket::getUniqueIdCounter()) {
                    std::cout << "Ticket is valid.\n";
                } else {
                    std::cout << "Ticket is not valid.\n";
                }
                break;
            }
            case 3:
                return;
            default:
                std::cerr << "Invalid choice in file.\n";
        }
    }

    file.close();
}
// Function for console menu
void consoleMenu() {
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
            case 3:
                std::cout << "\nExiting the program.\n";
                break;
            default: {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 3);
}

// Function for calling processFile() from console if the user chooses to read from a file
void readFromFile() {
    std::string fileName;
    std::cout << "Enter the filename: ";
    std::cin >> fileName;
    processFile(fileName);
}

void chooseInputMethod() {
    std::cout << "Do you want to enter data from the keyboard or read from a text file? (keyboard/file): ";
    std::string inputMethod;
    std::cin >> inputMethod;

    if (inputMethod == "file") {
        readFromFile();
    } else if (inputMethod == "keyboard") {
        consoleMenu();
    } else {
        std::cerr << "Invalid input. Please enter 'keyboard' or 'file'.\n";
        chooseInputMethod();
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {  // Command line arguments
        processFile(argv[1]);
    } else {  // Console menu
        chooseInputMethod();
        return 0;
    }
}

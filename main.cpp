#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include "FootballTicket.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<Ticket> tickets;

// Function prototype
void initLocAndEvent(Location& location, Event& event);
void generateFootballTicket(Location& location);
void validateTicket();
void processFile(const std::string& fileName);
void consoleMenu();
void readFromFile();
void loadTickets();
void saveTickets();

// Function for initializing Location and Event
void initLocAndEvent(Location& location, Event& event) {

    // User input for Location
    std::cin >> location;

    //new
    location.initializeSeats(); // Initialize the seating layout

    // User input for Event
    std::cin >> event;

    // Display Location details
    std::cout << "\nLocation Details:\n";
    location.displayLocationDetails();

    // Display Event details
    std::cout << "\nEvent Details:\n";
    event.displayEventDetails();
}

// Function to generate a football ticket
void generateFootballTicket(Location& location) {
    int zone, row;
    std::cout << "\nEnter Zone and Row for the football ticket: ";
    std::cin >> zone >> row;

    FootballTicket footballTicket("Football", zone, row);
    if (footballTicket.findAndAllocateSeat(location)) {
        footballTicket.displayTicketDetails();
        tickets.push_back(footballTicket);
    } else {
        std::cout << "No available seats in the specified zone and row." << std::endl;
    }
}

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
                //generateTicketOfType("Normal");
                break;
            }
            case 2: {
                //generateTicketOfType("VIP");
                break;
            }
            case 3: {
                // Validate Ticket
                validateTicket();
                break;
            }
            case 4: {
                std::cout << "\nExiting the program.\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    file.close();
}
// Ticket generation menu separated from consoleMenu
void ticketGenerationMenu(Location& location) {
    int choice;
    do {
        std::cout << "\n========== TICKET GENERATION MENU ==========\n";
        std::cout << "1. Generate Football Ticket\n";
        std::cout << "2. Generate Movie Ticket\n";  // Placeholder for future implementation
        std::cout << "3. Generate Theater Ticket\n";  // Placeholder for future implementation
        std::cout << "4. Back to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                generateFootballTicket(location);
                break;
            case 2:
                // Placeholder for generating movie ticket
                break;
            case 3:
                // Placeholder for generating theater ticket
                break;
            case 4:
                std::cout << "Returning to main menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// Function for console menu
void consoleMenu() {
    Location location;
    Event event;
    int choice;
    do {
        std::cout << "\n========== MAIN MENU ==========\n";
        std::cout << "1. Enter Ticket Details\n";
        std::cout << "2. Validate Ticket\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                initLocAndEvent(location, event);
                ticketGenerationMenu(location);
                break;
            case 2:
                validateTicket();
                break;
            case 3:
                std::cout << "\nExiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
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

// Function for calling consoleMenu() from console if the user chooses to enter data from the keyboard
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

// Function for loading tickets from file
void loadTickets() {
    std::ifstream  inFile("tickets.bin", std::ios::binary);
    while (inFile.peek() != EOF) {
        Ticket ticket;
        ticket.deserialize(inFile);
        tickets.push_back(ticket);
    }
    inFile.close();
    if (!tickets.empty()) {
        Ticket::updateUniqueIdCounter(tickets.back().getTicketId());
    }
}

// Function for saving tickets to file
void saveTickets() {
    std::ofstream outFile("tickets.bin", std::ios::binary | std::ios::trunc);
    if (!outFile) {
        std::cerr << "Error: Unable to open tickets.bin for writing." << std::endl;
        return;
    }
    for (const auto& ticket : tickets) {
        ticket.serialize(outFile);
        if (!outFile) {
            std::cerr << "Error: Write to tickets.bin failed." << std::endl;
            break;
        }
    }
    outFile.close();
}


// Function for validating a ticket
void validateTicket() {
    int ticketId;
    std::cout << "\nEnter Ticket ID to validate: ";
    std::cin >> ticketId;

    bool isValid = false;
    for (const auto& ticket : tickets) {
        if (ticket.getTicketId() == ticketId) {
            isValid = true;
            break;
        }
    }

    if (isValid) {
        std::cout << "Ticket is valid. \n";
    } else {
        std::cout << "Ticket is not valid.\n";
    }
}

int main(int argc, char* argv[]) {
    loadTickets();

    if (tickets.empty()) {
        std::cout << "No existing tickets found. Starting fresh." << std::endl;
    } else {
        std::cout << "Loaded existing tickets." << std::endl;
    }

    if (argc > 1) {  // Command line arguments
        processFile(argv[1]);
        saveTickets();
    } else {  // Console menu
        chooseInputMethod();
        saveTickets();
        return 0;
    }
}

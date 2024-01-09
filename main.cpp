#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include "FootballTicket.h"
#include "CinemaTicket.h"
#include "TheaterTicket.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

std::vector<Ticket> tickets;

// Function prototype
void initLocAndEvent(Location& location, Event& event);
void generateFootballTicket(Location& location);
void generateCinemaTicket(Location& location);
void generateTheaterTicket(Location& location);
void validateTicket();
void processFile(const std::string& fileName);
void consoleMenu();
void readFromFile();
void loadTickets();
void saveTickets();
void ticketGenerationMenu(Location& location);

// Function for initializing Location and Event
void initLocAndEvent(Location& location, Event& event) {

    // User input for Location
    std::cin >> location;

    // Initialize the seating layout
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
    std::cout << "\n========== Football Ticket Menu ==========\n";
    std::cout << "1. Stand: ";

    // Validate input
    while (!(std::cin >> zone) || zone < 1 || zone > location.getNumZones()) {
        std::cout << "Invalid input. Please enter a valid stand: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "2. Row: ";
    // Validate input
    while (!(std::cin >> row) || row < 1 || row > location.getNumRows()) {
        std::cout << "Invalid input. Please enter a valid row: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\n========== Football Ticket Menu ==========\n";

    FootballTicket footballTicket("Football Ticket", zone, row);
    if (footballTicket.findAndAllocateSeat(location)) {
        footballTicket.displayTicketDetails();
        tickets.push_back(footballTicket);
    } else {
        std::cout << "No available seats in the specified stand and row." << std::endl;
    }
}

// Function to generate a movie ticket
void generateCinemaTicket(Location& location) {
    int choice, zone, row;
    std::cout << "\n========== Cinema Ticket Menu ==========\n";
    std::cout << "1. Normal Ticket\n";
    std::cout << "2. VIP Ticket\n";
    std::cout << "========== Cinema Ticket Menu ==========\n";

    std::cout << "Enter your choice: ";
    // Validate input
    while (!(std::cin >> choice) || choice < 1 || choice > 2) {
        std::cout << "Invalid input. Please enter a valid choice: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Area: ";
    // Validate input
    while (!(std::cin >> zone) || zone < 1 || zone > location.getNumZones()) {
        std::cout << "Invalid input. Please enter a valid are: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Row: ";
    // Validate input
    while (!(std::cin >> row) || row < 1 || row > location.getNumRows()) {
        std::cout << "Invalid input. Please enter a valid row: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "\n========== Cinema Ticket Menu ==========\n";

    // Ternary operator to determine ticket type
    std::string ticketType = (choice == 1) ? "Normal Cinema Ticket " : "VIP Cinema Ticket";

    // Create a CinemaTicket object and allocate a seat
    CinemaTicket cinemaTicket(ticketType.c_str(), zone, row);
    if (cinemaTicket.findAndAllocateSeat(location)) {
        cinemaTicket.displayTicketDetails();
        tickets.push_back(cinemaTicket);
    } else {
        std::cout << "No available seats in the specified area and row." << std::endl;
    }
}

// Function to generate a theater ticket
void generateTheaterTicket(Location& location) {
    int choice, zone, row;
    std::cout << "\n========== Theater Ticket Menu ==========\n";
    std::cout << "1. Category 1 Ticket\n";
    std::cout << "2. Category 2 Ticket\n";
    std::cout << "3. Box Ticket\n";
    std::cout << "========== Theater Ticket Menu ==========\n";

    std::cout << "Enter your choice: ";

    // Validate input
    while (!(std::cin >> choice) || choice < 1 || choice > 3) {
        std::cout << "Invalid input. Please enter a valid choice: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Area: ";
    // Validate input
    while (!(std::cin >> zone) || zone < 1 || zone > location.getNumZones()) {
        std::cout << "Invalid input. Please enter a valid area: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Row: ";
    // Validate input
    while (!(std::cin >> row) || row < 1 || row > location.getNumRows()) {
        std::cout << "Invalid input. Please enter a valid row: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\n========== Cinema Ticket Menu ==========\n";

    // Ternary operator to determine ticket type
    std::string ticketType;
    if (choice == 1) {
        ticketType = "Category 1 Theater Ticket";
    } else if (choice == 2) {
        ticketType = "Category 2 Theater Ticket";
    } else {
        ticketType = "Box Theater Ticket";
    }

    // Create a TheaterTicket object and allocate a seat
    TheaterTicket theaterTicket(ticketType.c_str(), zone, row);
    if (theaterTicket.findAndAllocateSeat(location)) {
        theaterTicket.displayTicketDetails();
        tickets.push_back(theaterTicket);
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

    int choice;

    // Process Location and Event from file
    location.readFromFile(file);
    event.readFromFile(file);

    // Initialize the seating layout
    location.initializeSeats();

    // Display details
    location.displayLocationDetails();
    event.displayEventDetails();

    do {
        std::cout << "\n========== MAIN MENU ==========\n";
        std::cout << "1. Ticket Generation Menu\n";
        std::cout << "2. Validate Ticket\n";
        std::cout << "3. Exit\n";
        std::cout << "========== MAIN MENU ==========\n";
        std::cout << "Enter your choice: ";

        // Validate input
        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cout << "Invalid choice. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter your choice: ";
        }

        switch (choice) {
            case 1:
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

    file.close();
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
        std::cout << "========== MAIN MENU ==========\n";
        std::cout << "Enter your choice: ";

        // Validate input
        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cout << "Invalid choice. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter your choice: ";
        }

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

// Ticket generation menu separated from consoleMenu
void ticketGenerationMenu(Location& location) {
    int choice;
    do {
        std::cout << "\n========== TICKET GENERATION MENU ==========\n";
        std::cout << "1. Generate Football Ticket\n";
        std::cout << "2. Generate Movie Ticket\n";  // Placeholder for future implementation
        std::cout << "3. Generate Theater Ticket\n";  // Placeholder for future implementation
        std::cout << "4. Back to Main Menu\n";
        std::cout << "========== TICKET GENERATION MENU ==========\n";
        std::cout << "Enter your choice: ";
        // Validate input
        while (!(std::cin >> choice) || choice < 1 || choice > 4) {
            std::cout << "Invalid choice. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter your choice: ";
        }

        switch (choice) {
            case 1:
                generateFootballTicket(location);
                break;
            case 2:
                generateCinemaTicket(location);
                break;
            case 3:
                generateTheaterTicket(location);
                break;
            case 4:
                std::cout << "Returning to main menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// Function for calling processFile() from console if the user chooses to read from a file
void readFromFile() {
    std::string fileName;
    std::cout << "Enter the filename: ";
    // Validate input
    while (!(std::cin >> fileName)) {
        std::cout << "Invalid input. Please enter a valid filename: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
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

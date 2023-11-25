#include "Ticket.h"
#include <cstring>

int Ticket::uniqueIdCounter = 1000; // Initialize the static member

// Default constructor
Ticket::Ticket() : ticketId(0), ticketType(nullptr) {}

// Destructor
Ticket::~Ticket() {
    delete[] ticketType;
}

// Copy constructor
Ticket::Ticket(const Ticket &other) {
    // Allocate memory for ticketType and copy from the other object
    ticketType = new char[strlen(other.ticketType) + 1];
    strcpy(ticketType, other.ticketType);

    // Copy Ticket ID
    ticketId = other.ticketId;
}

// Accessors
int Ticket::getTicketId() const {
    return ticketId;
}

const char* Ticket::getTicketType() const {
    return ticketType;
}

int Ticket::getUniqueIdCounter() {
    return uniqueIdCounter;
}

// Other processing methods
void Ticket::generateTicketId() {
    // Generate a unique ticket ID based on the static counter
    ticketId = ++uniqueIdCounter;
}

void Ticket::displayTicketDetails() const {
    std::cout << "Ticket ID: " << ticketId << "\n";
    std::cout << "Ticket Type: " << ticketType << "\n";
}

// Setters with validations
void Ticket::setTicketType(const char* type) {
    // Validate the input (type should not be empty)
    if (type == nullptr || strlen(type) == 0) {
        std::cerr << "Invalid ticket type. Please provide a non-empty type.\n";
        return;
    }

    // Free existing memory
    delete[] ticketType;

    // Allocate memory for ticketType and copy the input string
    ticketType = new char[strlen(type) + 1];
    strcpy(ticketType, type);
}


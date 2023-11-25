#include "Ticket.h"
#include <cstring>

int Ticket::uniqueIdCounter = 1000; // Initialize the static member

// Default constructor
Ticket::Ticket() : ticketId(0), ticketType(nullptr) {}

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


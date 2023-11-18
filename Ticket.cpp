#include "Ticket.h"
#include <cstring>

int Ticket::uniqueIdCounter = 1000; // Initialize the static member

// Accessors
int Ticket::getTicketId() const {
    return ticketId;
}

const char* Ticket::getTicketType() const {
    return ticketType;
}


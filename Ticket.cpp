#include "Ticket.h"
#include <cstring>

int Ticket::uniqueIdCounter = 1000; // Initialize the static member

// Default constructor
Ticket::Ticket() : ticketId(0), ticketType(nullptr) {}

// Parameterized constructor
Ticket::Ticket(const char* type) {
    // Allocate memory for ticketType and copy the input string
    ticketType = new char[strlen(type) + 1];
    strcpy(ticketType, type);

    // Generate a unique ticket ID
    generateTicketId();
}

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

// Copy assignment operator
Ticket& Ticket::operator=(const Ticket &other) {
    if(this != &other) {
        // Free existing memory
        delete[] ticketType;

        // Copy values from the other object
        ticketType = new char[strlen(other.ticketType) + 1];
        strcpy(ticketType, other.ticketType);

        // Copy ticket ID
        ticketId = other.ticketId;
    }
    return *this;
}

// Accessors
int Ticket::getTicketId() const {
    return ticketId;
}

const char* Ticket::getTicketType() const {
    return ticketType;
}

// Other processing methods
void Ticket::generateTicketId() {
    // Generate a unique ticket ID based on the static counter
    ticketId = ++uniqueIdCounter;
}

void Ticket::displayTicketDetails() const {
    std::cout << "\n========== Ticket Details ==========\n";
    std::cout << "Ticket Type: " << (ticketType ? ticketType : "N/A") << "\n";
    std::cout << "Unique ID: " << ticketId << "\n";
    std::cout << "========== Ticket Details ==========\n";
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

// Public static member function to get uniqueIdCounter value
int Ticket::getUniqueIdCounter() {
    return uniqueIdCounter;
}

// Public static member function to update uniqueIdCounter value
void Ticket::updateUniqueIdCounter(int lastId) {
    uniqueIdCounter = lastId;
}

// Serialize method
void Ticket::serialize(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&ticketId), sizeof(ticketId));
    size_t length = strlen(ticketType);
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(ticketType, length);
}

// Deserialize method
void Ticket::deserialize(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&ticketId), sizeof(ticketId));
    size_t length;
    in.read(reinterpret_cast<char*>(&length), sizeof(length));
    delete[] ticketType;
    ticketType = new char[length + 1];
    in.read(ticketType, length);
    ticketType[length] = '\0';
}
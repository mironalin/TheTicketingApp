#include "Ticket.h"
#include <cstring>
#include <chrono>

int Ticket::uniqueIdCounter = 1000; // Initialize the static member

// Default constructor
Ticket::Ticket() : ticketId(0), ticketType(nullptr) {}

// Parameterized constructor
Ticket::Ticket(const char* type) {
    // Validate the input (type should not be empty)
    if (type == nullptr || strlen(type) == 0) {
        std::cerr << "Invalid ticket type. Please provide a non-empty type.\n";
        ticketType = nullptr;
        ticketId = 0;
        return;
    }

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
    // Use a combination of a static counter and the current time
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    // Combine the current time in milliseconds with the static counter
    ticketId = millis + (++uniqueIdCounter);
    // Make the id positive
    if (ticketId < 0) {
        ticketId *= -1;
    }
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

// Serialize method with validation
void Ticket::serialize(std::ofstream& out) const {
    if (!out) {
        std::cerr << "Output file stream is not in a good state.\n";
        return;
    }
    out.write(reinterpret_cast<const char*>(&ticketId), sizeof(ticketId));
    size_t length = strlen(ticketType);
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(ticketType, length);
    if (!out) {
        std::cerr << "Failed to write to the output file stream.\n";
    }
}

// Deserialize method with validation
void Ticket::deserialize(std::ifstream& in) {
    if (!in) {
        std::cerr << "Input file stream is not in a good state.\n";
        return;
    }
    in.read(reinterpret_cast<char*>(&ticketId), sizeof(ticketId));
    size_t length;
    in.read(reinterpret_cast<char*>(&length), sizeof(length));
    delete[] ticketType;
    ticketType = new char[length + 1];
    in.read(ticketType, length);
    ticketType[length] = '\0';
    if (!in) {
        std::cerr << "Failed to read from the input file stream.\n";
    }
}

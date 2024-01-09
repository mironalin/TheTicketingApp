#include "FootballTicket.h"
#include "Location.h"
#include <iostream>


// Implementing the constructors
FootballTicket::FootballTicket() : Ticket(), zone(0), row(0) {}

FootballTicket::FootballTicket(const char* type, int z, int r) : Ticket(type), zone(z), row(r) {
}

// Implementing the accessors
int FootballTicket::getZone() const {
    return zone;
}

int FootballTicket::getRow() const {
    return row;
}

// Implementing the display function
void FootballTicket::displayTicketDetails() const {
    std::cout << "\n========== Ticket Details ==========\n";
    std::cout << "Ticket Type: " << (getTicketType() ? getTicketType() : "N/A") << "\n";
    std::cout << "Unique ID: " << getTicketId() << "\n";
    std::cout << "Stadium zone: " << zone << "\n";
    std::cout << "Stadium row: " << row << "\n";
    std::cout << "Seat Number: " << seatNumber << std::endl;  // Output the seat number
    std::cout << "========== Ticket Details ==========\n";
}

bool FootballTicket::findAndAllocateSeat(Location& location) {
    auto [assignedRow, assignedSeat] = location.findAvailableSeat(zone, row);
    if (assignedRow != -1 && assignedSeat != -1) {
        location.allocateSeat(zone, assignedRow, assignedSeat);
        generateTicketId();
        this->seatNumber = assignedSeat;  // Store the seat number
        return true;
    } else {
        std::cerr << "No available seats in the specified zone and row.\n";
        return false;
    }
}

// Implement the serialize and deserialize methods
void FootballTicket::serialize(std::ofstream& out) const {
    Ticket::serialize(out);  // Serialize base class data
    out.write(reinterpret_cast<const char*>(&zone), sizeof(zone));
    out.write(reinterpret_cast<const char*>(&row), sizeof(row));
    out.write(reinterpret_cast<const char*>(&seatNumber), sizeof(seatNumber));
}

void FootballTicket::deserialize(std::ifstream& in) {
    Ticket::deserialize(in);  // Deserialize base class data
    in.read(reinterpret_cast<char*>(&zone), sizeof(zone));
    in.read(reinterpret_cast<char*>(&row), sizeof(row));
    in.read(reinterpret_cast<char*>(&seatNumber), sizeof(seatNumber));
}
#include "CinemaTicket.h"
#include "Location.h"
#include <iostream>

// Implement the default constructor
CinemaTicket::CinemaTicket() : Ticket(), zone(0), row(0), seatNumber(0) {}

// Implement the parameterized constructor
CinemaTicket::CinemaTicket(const char* type, int z, int r) : Ticket(type), zone(z), row(r), seatNumber(0) {}

// Implement the accessors
int CinemaTicket::getZone() const {
    return zone;
}

int CinemaTicket::getRow() const {
    return row;
}

// Implement the display function
void CinemaTicket::displayTicketDetails() const {
    std::cout << "\n========== Ticket Details ==========\n";
    std::cout << "Ticket Type: " << (getTicketType() ? getTicketType() : "N/A") << "\n";
    std::cout << "Unique ID: " << getTicketId() << "\n";
    std::cout << "Cinema zone: " << zone << "\n";
    std::cout << "Cinema row: " << row << "\n";
    std::cout << "Seat Number: " << seatNumber << std::endl;  // Output the seat number
    std::cout << "========== Ticket Details ==========\n";
}

// Implement the findAndAllocateSeat function
bool CinemaTicket::findAndAllocateSeat(Location& location) {
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
void CinemaTicket::serialize(std::ofstream& out) const {
    Ticket::serialize(out);  // Serialize base class data
    out.write(reinterpret_cast<const char*>(&zone), sizeof(zone));
    out.write(reinterpret_cast<const char*>(&row), sizeof(row));
    out.write(reinterpret_cast<const char*>(&seatNumber), sizeof(seatNumber));
}

void CinemaTicket::deserialize(std::ifstream& in) {
    Ticket::deserialize(in);  // Deserialize base class data
    in.read(reinterpret_cast<char*>(&zone), sizeof(zone));
    in.read(reinterpret_cast<char*>(&row), sizeof(row));
    in.read(reinterpret_cast<char*>(&seatNumber), sizeof(seatNumber));
}
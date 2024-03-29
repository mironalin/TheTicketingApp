#ifndef THETICKETINGAPP_FOOTBALLTICKET_H
#define THETICKETINGAPP_FOOTBALLTICKET_H

#include "Ticket.h"
#include "Location.h"

class FootballTicket : public Ticket {
private:
    int zone;
    int row;

    int seatNumber;  // Add a member variable for seat number

public:
    // Constructors
    FootballTicket();
    FootballTicket(const char* type, int zone, int row);

    // Accessors
    int getZone() const;
    int getRow() const;

    // Other methods
    virtual void displayTicketDetails() const override;

    // Function to find and allocate a seat
    bool findAndAllocateSeat(Location& location);  // Implement based on your seating arrangement logic

    // Serialize and deserialize methods
    virtual void serialize(std::ofstream& out) const;
    virtual void deserialize(std::ifstream& in);
};

#endif //THETICKETINGAPP_FOOTBALLTICKET_H

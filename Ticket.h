//
// Created by alinm on 11/17/2023.
//

#ifndef THETICKETINGAPP_TICKET_H
#define THETICKETINGAPP_TICKET_H

#include <iostream>
#include <fstream>

class Ticket {
private:
    int ticketId;
    char* ticketType;
    static int uniqueIdCounter;

public:
    // Default constructor
    Ticket();
    Ticket(const char* type);

    // Destructor
    ~Ticket();

    // Copy constructor
    Ticket(const Ticket& other);

    // Copy assignment operator
    Ticket& operator=(const Ticket& other);

    // Accessors
    int getTicketId() const;
    const char* getTicketType() const;

    // Other processing methods
    void generateTicketId();
    void displayTicketDetails() const;

    // Setters with validations
    void setTicketType(const char* type);

    // Public static member function to get uniqueIdCounter value
    static int getUniqueIdCounter();

    // Public static member function to update uniqueIdCounter value
    static void updateUniqueIdCounter(int lastId);

    // Serialize and deserialize methods
    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);
};

#endif //THETICKETINGAPP_TICKET_H

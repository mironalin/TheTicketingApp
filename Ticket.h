//
// Created by alinm on 11/17/2023.
//

#ifndef THETICKETINGAPP_TICKET_H
#define THETICKETINGAPP_TICKET_H

#include <iostream>

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
};

#endif //THETICKETINGAPP_TICKET_H

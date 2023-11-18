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
    // Accessors
    int getTicketId() const;
    const char* getTicketType() const;
    static int getUniqueIdCounter();

    // Setters with validations
    void setTicketType(const char* type);
};

#endif //THETICKETINGAPP_TICKET_H

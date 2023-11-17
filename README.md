# Event Ticket Management System

## Project Description

This C++ application manages tickets for various events such as movies, plays, and football matches. It provides functionalities for reading and managing the characteristics of both the event location and the event itself. The application allows the generation of nominal tickets with unique IDs and provides a menu for users to input location and event details, generate tickets, and later validate them.

## Functionalities

- Read characteristics of the event location (e.g., maximum number of seats, number of rows, zones, number/coding of seats per row, etc.)
- Read characteristics of the event (e.g., date, time, name, etc.)
- Generate nominal tickets according to desired characteristics (e.g., VIP, lawn, tribune, boxes, etc.)
- Unique ID generation for tickets
- Menu-driven interface for user input, ticket generation, and validation
- Error handling for invalid input values
- No external libraries; implemented using standard C++ libraries

## Example Scenarios

1. Issuing football tickets in a stadium with two stands (Stand 1 and Stand 2).
2. Issuing movie tickets in Normal or VIP categories.
3. Issuing theater tickets from Category 1, Category 2, and Box categories.

### Implementation Details

- Each class is implemented in its own header and/or cpp file.
- The main function is located in another cpp file.

Feel free to explore the code in the respective header and cpp files for detailed implementations.

## Usage

1. Clone the repository.
2. Compile the project using a C++ compiler.
3. Run the executable.

For detailed instructions on using the application, refer to the user manual provided in the repository.

## Contributors

- Alin Miron
## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

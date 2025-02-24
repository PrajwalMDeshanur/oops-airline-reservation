#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <ctime>
using namespace std;
using std::string;

// Global counter to track the number of confirmed tickets.
int c = 0;

//---------------------------------------------------------
// Class: Airport
// Purpose: Represents an airport with a name and location.
//---------------------------------------------------------
class Airport {
public:
    string airportName;
    string airLocation;

    // Default constructor: Initializes airport details to "NULL".
    Airport() {
        airportName = "NULL";
        airLocation = "NULL";
    }

    // Parameterized constructor: Sets airport name and location.
    Airport(string airportName, string airLocation) {
        this->airportName = airportName;
        this->airLocation = airLocation;
    }

    // Prints a welcome message for the airport.
    void printAirport() {
        cout << "Welcome to " << airportName << " " << airLocation << endl << endl;
    }
};

//---------------------------------------------------------
// Abstract Class: Employee
// Purpose: Base class for all employees with common details.
//---------------------------------------------------------
class Employee {
public:
    string empName;
    string empId;
    double salary;
    int experience;

    // Default constructor.
    Employee() {
        empName = "NULL";
        empId = "NULL";
        salary = 0;
        experience = 0;
    }

    // Parameterized constructor.
    Employee(string empName, string empId, double salary, int experience) {
        this->empName = empName;
        this->empId = empId;
        this->salary = salary;
        this->experience = experience;
    }

    // Pure virtual function makes this an abstract class.
    virtual void printEmployee() = 0;
};

//---------------------------------------------------------
// Class: AirportEmployee (Derived from Employee)
// Purpose: Represents airport staff with an added designation.
//---------------------------------------------------------
class AirportEmployee : public Employee {
public:
    string designation;

    // Default constructor.
    AirportEmployee() : Employee() {
        designation = "NULL";
    }

    // Parameterized constructor.
    AirportEmployee(string empName, string empId, double salary, int experience, string designation)
        : Employee(empName, empId, salary, experience) {
        this->designation = designation;
    }

    // Implements printEmployee to display airport employee details.
    void printEmployee() {
        cout << "Name:" << empName << endl;
        cout << "Id:" << empId << endl;
        cout << "Experience:" << experience << endl;
        cout << "Salary:" << salary << endl;
        cout << "Designation:" << designation << endl;
    }
};

//---------------------------------------------------------
// Class: AirlineEmployee (Derived from Employee)
// Purpose: Represents airline staff with their designation.
//---------------------------------------------------------
class AirlineEmployee : public Employee {
public:
    string designation;

    // Default constructor.
    AirlineEmployee() : Employee() {
        designation = "NULL";
    }

    // Parameterized constructor.
    AirlineEmployee(string empName, string empId, double salary, int experience, string designation)
        : Employee(empName, empId, salary, experience) {
        this->designation = designation;
    }

    // Implements printEmployee for airline employees.
    void printEmployee() {
        cout << "Name:" << empName << endl;
        cout << "Id:" << empId << endl;
        cout << "Experience:" << experience << endl;
        cout << "Salary:" << salary << endl;
        cout << designation;
    }
};

//---------------------------------------------------------
// Class: ApplicationException
// Purpose: Custom exception class to handle application errors.
//---------------------------------------------------------
class ApplicationException {
public:
    string errMsg;

    // Default constructor.
    ApplicationException() {
        errMsg = "NULL";
    }

    // Parameterized constructor to set error message.
    ApplicationException(string errMsg) {
        this->errMsg = errMsg;
    }

    // Prints the exception message.
    printException() {
        cout << errMsg << endl;
    }
};

//---------------------------------------------------------
// Class: BankAccount
// Purpose: Models a bank account for net banking payments.
//---------------------------------------------------------
class BankAccount {
public:
    int accNo;
    double balance;

    // Default constructor.
    BankAccount() {
        accNo = 0;
        balance = 0;
    }

    // Parameterized constructor.
    BankAccount(int accNo, double balance) {
        this->accNo = accNo;
        this->balance = balance;
    }

    // Attempts to debit the account; returns 1 if insufficient funds.
    int debitAccount(int amt) {
        if (amt > balance) {
            return 1;
        }
        balance = balance - amt;
        return 0;
    }
};

//---------------------------------------------------------
// Abstract Class: Card
// Purpose: Base class for payment cards.
//---------------------------------------------------------
class Card {
public:
    long int cardNo;
    string expDate;

    // Default constructor.
    Card() {
        cardNo = 0;
        expDate = "NULL";
    }

    // Parameterized constructor.
    Card(long int a, string b) {
        cardNo = a;
        expDate = b;
    }

    // Pure virtual function for processing payments.
    virtual int payAmount(double amt) = 0;

    // Prints card details.
    void printCard() {
        cout << cardNo << " " << expDate << endl;
    }
};

//---------------------------------------------------------
// Class: CreditCard (Derived from Card)
// Purpose: Handles credit card payments with a credit limit.
//---------------------------------------------------------
class CreditCard : public Card {
public:
    string cardType;
    double maxLimit;
    double credAmount;

    // Default constructor.
    CreditCard() {
        cardNo = 0;
        expDate = "NULL";
        cardType = "NULL";
        maxLimit = 0;
        credAmount = 0;
    }

    // Parameterized constructor.
    CreditCard(long int a, string b, string c, double d, double e) {
        cardNo = a;
        expDate = b;
        cardType = c;
        maxLimit = d;
        credAmount = e;
    }

    // Prints credit card details.
    void printCreditCard() {
        cout << cardNo << " " << expDate << " " << cardType << " " << maxLimit << " " << credAmount << endl;
    }

    // Processes payment; checks if the credit limit is exceeded.
    int payAmount(double amt) {
        if (credAmount + amt > maxLimit) {
            return 1;
        }
        credAmount = credAmount + amt;
        return 0;
    }
};

//---------------------------------------------------------
// Class: DebitCard (Derived from Card)
// Purpose: Handles debit card payments by using available balance.
//---------------------------------------------------------
class DebitCard : public Card {
public:
    string cardType;
    double balance;

    // Default constructor.
    DebitCard() : Card() {
        cardType = "NULL";
        balance = 0;
    }

    // Parameterized constructor.
    DebitCard(long int cardNo, string expDate, string cardType, double balance)
        : Card(cardNo, expDate) {
        this->cardType = cardType;
        this->balance = balance;
    }

    // Prints debit card details.
    void printDebitCard() {
        cout << cardNo << " " << expDate << " " << cardType << " " << balance << endl;
    }

    // Processes payment; checks if sufficient balance is available.
    int payAmount(double amt) {
        if (amt > balance) {
            return 1;
        }
        balance = balance - amt;
        return 0;
    }
};

//---------------------------------------------------------
// Class: Luggage
// Purpose: Represents a passenger's luggage and calculates overweight fees.
//---------------------------------------------------------
class Luggage {
public:
    int lugId;
    double weight;
    int noOfLug;
    double amtPaid;

    // Default constructor.
    Luggage() {
        lugId = 0;
        weight = 0;
        noOfLug = 0;
        amtPaid = 0;
    }

    // Parameterized constructor.
    Luggage(int lugId, int weight, int noOfLug) {
        this->lugId = lugId;
        this->weight = weight;
        this->noOfLug = noOfLug;
        amtPaid = 0;
    }

    // Prints luggage details.
    void printLuggage() {
        cout << "Id:" << lugId << endl;
        cout << "Weight:" << weight << endl;
        cout << "Number Of Luggage:\n" << noOfLug;
        cout << "Amount Paid:\n" << amtPaid;
    }

    // Checks if luggage exceeds the allowed weight (12kg) and computes extra fee.
    void checkLuggage() {
        if (weight > 12) {
            amtPaid = (weight - 12) * 600;
        }
    }
};

//---------------------------------------------------------
// Class: Flight
// Purpose: Contains flight details such as flight ID, name, capacity, and timings.
//---------------------------------------------------------
class Flight {
public:
    string flightId;
    string fname;
    int capacity;
    string arrivalTime;
    string departureTime;
    string destination;

    // Default constructor.
    Flight() {
        flightId = "NULL";
        fname = "NULL";
        capacity = 0;
        arrivalTime = "NULL";
        departureTime = "NULL";
        destination = "NULL";
    }

    // Parameterized constructor.
    Flight(string flightId, string fname, int capacity, string arrivalTime, string departureTime, string destination) {
        this->flightId = flightId;
        this->fname = fname;
        this->capacity = capacity;
        this->arrivalTime = arrivalTime;
        this->departureTime = departureTime;
        this->destination = destination;
    }

    // Prints flight details.
    void printFlight() {
        cout << "flightId= " << flightId << "\nflight name= " << fname << "\nCapacity" << capacity
             << "\narrivalTime= " << arrivalTime << "\ndepartureTime= " << departureTime << endl << endl;
    }
};

//---------------------------------------------------------
// Abstract Class: BookingStatus
// Purpose: Represents the status of a ticket booking.
//---------------------------------------------------------
class BookingStatus {
public:
    // Pure virtual function for printing the current booking status.
    virtual void print() = 0;
};

//---------------------------------------------------------
// Class: Processing (Derived from BookingStatus)
// Purpose: Indicates that the booking process is ongoing.
//---------------------------------------------------------
class Processing : public BookingStatus {
public:
    void print() {
        cout << "Under the process" << endl;
    }
};

//---------------------------------------------------------
// Class: Confirm (Derived from BookingStatus)
// Purpose: Indicates a successful booking.
//---------------------------------------------------------
class Confirm : public BookingStatus {
public:
    void print() {
        cout << "Ticket booked successfully";
        c++; // Increment the global counter for confirmed tickets.
    }
};

//---------------------------------------------------------
// Class: Aborted (Derived from BookingStatus)
// Purpose: Indicates a failed or aborted booking.
//---------------------------------------------------------
class Aborted : public BookingStatus {
public:
    void print() {
        cout << "Sorry!!Process aborted/failed ";
        cout << "Unable to book ticket ";
    }
};

//---------------------------------------------------------
// Class: TicketCounter
// Purpose: Handles ticket booking, flight selection, and payment processing.
//---------------------------------------------------------
class TicketCounter {
public:
    int tid;
    string source;
    string destination;
    double price;
    BookingStatus *currentStatus;
    // Array of flight pointers for available flights.
    Flight *f[5], ho;
    string classType; // Stores the selected class type.
    string g;         // Stores additional service input.
    int h;            // Payment method selection input.
    int j = 0;        // Counter for payment attempts.

    // Default constructor.
    TicketCounter() {
        tid = 0;
        source = "NULL";
        destination = "NULL";
        price = 0;
        currentStatus = new Processing();
    }

    // Parameterized constructor.
    TicketCounter(int tid, string source, string destination, double price) {
        this->tid = tid;
        this->source = source;
        this->destination = destination;
        this->price = price;
        currentStatus = new Processing();
    }

    // Prints ticket details.
    void printTicket() {
        cout << "Ticket Id= " << tid << "\n Source= " << source << "\n destination= " << destination << "\n price= " << price << endl << endl;
    }

    // Books a ticket by processing payment and calculating additional charges.
    void bookTicket(BookingStatus *x, BankAccount *b2, Luggage l1, Card *card, CreditCard ca1, DebitCard da1) {
        currentStatus = x;
        double c = classTypePrice();    // Calculate extra charge based on selected class.
        double d = additionalServices();  // Calculate extra service charges.

        // Set status to processing and print initial status.
        currentStatus = new Processing;
        cout << endl << "Ticket Booking is ";
        statusPrint();

        cout << "-------------- Ticket Details -------------------" << endl;
        printTicket();

        cout << "----------------Flight details from Source to Destination------------------------" << endl;
        // Loop through available flights to find the matching destination.
        for (int i = 0; i < 5; i++) {
            if (f[i]->destination == destination) {
                f[i]->printFlight();
                ho = *f[i];
            }
        }

        cout << "Additional charges are" << endl;
        // Check for overweight luggage fees.
        l1.checkLuggage();
        cout << "Overweight Luggage Charge=" << l1.amtPaid << endl;
        cout << "Class type charges=" << c << endl;
        cout << "Service charge=" << d << endl << endl;

        // Calculate the final ticket price.
        price = TotalPrice(l1.amtPaid, c, d);
        cout << "-------Total Price------\n";
        cout << "Total price of Ticket Booking is " << price << endl << endl;
        int j = 0;
        // Allow up to three payment attempts.
        while (j < 3) {
            cout << "Enter the mode of payment \n 1.Credit Card 2.Debit Card 3.Net Banking " << endl;
            cin >> h;

            if (h == 2) { // Debit Card payment.
                card = &da1;
                int a = card->payAmount(price);
                if (a == 1) { // Payment fails due to insufficient balance.
                    currentStatus = new Aborted;
                    cout << "|----------------------------------------------------------------|" << endl;
                    statusPrint();
                    cout << " Failed due to insufficient balance         |" << endl;
                    cout << "|----------------------------------------------------------------|" << endl << endl;
                    j++;
                    cout << "use another payment method" << endl;
                }
                else {
                    currentStatus = new Confirm;
                    cout << "**************************************" << endl;
                    statusPrint();
                    cout << "     " << endl;
                    cout << "**************************************" << endl;
                    break;
                }
            }
            else if (h == 3) { // Net Banking payment.
                int a = b2->debitAccount(price);
                if (a == 1) {
                    currentStatus = new Aborted;
                    cout << "|-----------------------------------------------------------------|" << endl;
                    statusPrint();
                    cout << "Due to insufficient balance            " << endl;
                    cout << "|-----------------------------------------------------------------|" << endl;
                    j++;
                    cout << endl;
                    cout << "use another payment method" << endl;
                }
                else {
                    currentStatus = new Confirm;
                    cout << "**************************************" << endl;
                    cout << "|     ";
                    statusPrint();
                    cout << "     |" << endl;
                    cout << "**************************************" << endl;
                    break;
                }
            }
            else { // Default: Credit Card payment.
                card = &ca1;
                int a = card->payAmount(price);
                if (a == 1) {
                    currentStatus = new Aborted;
                    cout << "|---------------------------------------------------------------------|" << endl;
                    cout << "|";
                    statusPrint();
                    cout << "Maximum credit limit amount exceeded  |" << endl;
                    cout << "|----------------------------------------------------------------------|" << endl;
                    j++;
                    cout << endl;
                    cout << "use another payment method" << endl;
                }
                else {
                    currentStatus = new Confirm;
                    cout << "**************************************" << endl;
                    cout << "|     ";
                    statusPrint();
                    cout << "     |" << endl;
                    cout << "**************************************" << endl;
                    break;
                }
            }
        }
        // If all payment methods fail after three attempts, throw an exception.
        if (j == 3) {
            throw ApplicationException("All payment methods are failed try next time");
        }
    }

    // Prints the current booking status.
    void statusPrint() {
        currentStatus->print();
    }

    // Asks the user for ticket class and returns the corresponding extra charge.
    double classTypePrice() {
        cout << "Enter the ticket class you want:" << endl;
        cout << "1.economy  2.premium economy  3.business class\n";
        cin >> classType;
        int b = 0;
        if (classType == "economy") {
            // Economy: no extra charge.
        }
        else if (classType == "premium economy") {
            b = 500;
            return b;
        }
        else if (classType == "business class") {
            b = 1500;
            return b;
        }
        else {
            b = 2500;
            return b;
        }
        return b;
    }

    // Asks the user if additional services are required and returns a fixed service charge.
    double additionalServices() {
        cout << "Do u want additional services like meal,lounge access etc" << endl;
        cin >> g;
        if (g == "yes" || g == "Yes")
            return 2000;
        return 0;
    }

    // Calculates and returns the total ticket price including extra charges.
    double TotalPrice(double h, double c, double d) {
        price = price + h + c + d;
        return price;
    }
};

//---------------------------------------------------------
// Class: Passengers
// Purpose: Represents a passenger and manages ticket booking.
//---------------------------------------------------------
class Passengers {
public:
    string pasName;
    int pasId;
    int age;
    long int phoneNo;
    string email;
    string ticketBooked;
    BankAccount *b2;
    Card *card;
    Luggage la;

    // Default constructor.
    Passengers() {
        pasName = "NULL";
        pasId = 0;
        age = 0;
        phoneNo = 0;
        email = "NULL";
        ticketBooked = "NULL";
    }

    // Parameterized constructor.
    Passengers(string pasName, int pasId, int age, int phoneNo, string email, string ticketBooked, Luggage l1) {
        this->pasName = pasName;
        this->pasId = pasId;
        this->age = age;
        this->phoneNo = phoneNo;
        this->email = email;
        this->ticketBooked = ticketBooked;
        la = l1;
    }

    // Prints passenger details.
    void printPassengers() {
        cout << pasName << " " << pasId << " " << age << " " << phoneNo << " " << email << " " << ticketBooked << endl;
    }

    // Initiates the ticket booking process if no ticket is booked.
    void ticketBook(TicketCounter t1, CreditCard ca1, DebitCard da1) {
        if (ticketBooked == "no") {
            t1.bookTicket(new Processing, b2, la, card, ca1, da1);
        }
    }
};

//---------------------------------------------------------
// Class: NoticeBoard
// Purpose: Displays flight information similar to an airport display board.
//---------------------------------------------------------
class NoticeBoard {
public:
    Flight *f1[5]; // Array of flight pointers.

    // Prints flight details in a formatted table.
    void flightDisplay() {
        cout << "|Flight Name     |Flight ID       |Boarding Time          | Departure Time         |" << endl;
        cout << endl;
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ") " << f1[i]->fname << "|" << f1[i]->flightId << "|" << f1[i]->arrivalTime << "|" << f1[i]->departureTime << "" << endl;
        }
    }
};

//---------------------------------------------------------
// Main Function
// Purpose: Simulates the airport reservation and management system workflow.
//---------------------------------------------------------
int main() {
    int n = 0; // Counter for number of seats booked.

    // Create luggage objects for different passengers.
    Luggage l1(456, 15, 1), l2(478, 20, 2), l3(479, 10, 3), l4(480, 18, 4);

    // Create passenger objects with initial details.
    Passengers p1("Prajwal", 123, 17, 4648463415, "prajwal@gmail.com", "no", l1);
    Passengers p2("Akshay", 125, 20, 4788526325, "Akshay@gmail.com", "no", l2);
    Passengers p3("Santosh", 130, 18, 4567891230, "Santosh@gmail.com", "no", l3);
  

    // Create an airport object.
    Airport a1("Kempegowda International Airport", "Bangalore");

    // Create a TicketCounter object with base details.
    TicketCounter t1(52697, "Bangalore", "Delhi", 3000);

    string f; // Used for user input (passport check).

    // Create airport employee objects.
    AirportEmployee ae1("Ganesh", "EMP001", 20000, 5, "Entrance Verifier");
    AirportEmployee ae2("Rajendra", "EMP002", 22000, 4, "Ticket Counter");

    // Array of employee pointers demonstrating polymorphism.
    Employee *e1[2];
    e1[0] = &ae1;
    e1[1] = &ae2;

    cout << "                            Airport Reservation and Management         \n";
    cout << "------------------------" << endl;

    //------------- Passenger 1 Flow -------------
    cout << "Passenger 1 Details:\n";
    p1.printPassengers();
    cout << "------------------------\n";
    cout << "Airport Security\n" << endl;
    e1[0]->printEmployee();  // Security employee checks.
    cout << "Checks for passport of passengers " << endl;
    cout << "Check if passport is present " << endl;
    cin >> f;
    if (f == "yes" || f == "Yes") {
        try {
            a1.printAirport();
            cout << "Ticket Booking Employee\n";
            // e1[1]->printEmployee();  // (Optional display of booking employee)

            // Setup bank account for Passenger 1.
            p1.b2 = new BankAccount(123456, 50000);

            // Initialize available flights for the ticket counter.
            t1.f[0] = new Flight("AIR001", "Air India", 300, "11:30", "12:00", "Delhi");
            t1.f[1] = new Flight("AIR002", "Indigo Airlines", 250, "10:00", "11:00", "America");
            t1.f[2] = new Flight("AIR023", "Qatar Airlines", 350, "14:10", "15:00", "Dubai");
            t1.f[3] = new Flight("AIR056", "Air Asia Airlines", 260, "12:00", "13:00", "Nepal");
            t1.f[4] = new Flight("AIR002", "Emirates Airlines", 300, "19:19", "20:00", "Srilanka");

            // Create payment card objects for Passenger 1.
            CreditCard ca1(14588623574123, "12-2-2040", "regular", 40000, 30000);
            DebitCard da1(14588623577551, "26-2-2045", "business", 10000);

            // Start the ticket booking process for Passenger 1.
            p1.ticketBook(t1, ca1, da1);
            cout << endl;

            // Display the notice board with flight details.
            NoticeBoard n1;
            n1.f1[0] = new Flight("AIR001", "Air India", 300, "11:30", "12:00", "Delhi");
            n1.f1[1] = new Flight("AIR002", "Indigo Airlines", 250, "10:00", "11:00", "America");
            n1.f1[2] = new Flight("AIR023", "Qatar Airlines", 350, "14:10", "15:00", "Dubai");
            n1.f1[3] = new Flight("AIR056", "Air Asia Airlines", 260, "12:00", "13:00", "Nepal");
            n1.f1[4] = new Flight("AIR002", "Emirates Airlines", 300, "19:19", "20:00", "Srilanka");
            cout << "-----------------Notice Board Display------------------\n";
            n1.flightDisplay();
            n++;
        }
        catch (ApplicationException &ab) {
            ab.printException();
        }
    }
    else {
        cout << "Unable enter the Airport" << endl;
    }

    //------------- Passenger 2 Flow -------------
    cout << endl << "--------------------Passenger 2 ----------------------\n";
    cout << "Passenger 2 Details:\n";
    p2.printPassengers();
    cout << "--------------------------\n";
    cout << "Airport Security for Checking Passport of Passengers " << endl;
    cout << "Check if passport is present " << endl;
    cin >> f;
    if (f == "yes" || f == "Yes") {
        try {
            a1.printAirport();
            cout << "Ticket Booking Employee\n";
            e1[1]->printEmployee();

            // Setup bank account for Passenger 2.
            p2.b2 = new BankAccount(810456, 1000);
            CreditCard ca2(145886752652, "18-3-2045", "regular", 40000, 3000);
            DebitCard da2(1458862385412, "28-2-2030", "business", 100000);
            p2.ticketBook(t1, ca2, da2);
            cout << endl;

            // Display the notice board.
            NoticeBoard n1;
            n1.f1[0] = new Flight("AIR001", "Air India", 300, "11:30", "12:00", "Delhi");
            n1.f1[1] = new Flight("AIR002", "Indigo Airlines", 250, "10:00", "11:00", "America");
            n1.f1[2] = new Flight("AIR023", "Qatar Airlines", 350, "14:10", "15:00", "Dubai");
            n1.f1[3] = new Flight("AIR056", "Air Asia Airlines", 260, "12:00", "13:00", "Nepal");
            n1.f1[4] = new Flight("AIR002", "Emirates Airlines", 300, "19:19", "20:00", "Srilanka");
            cout << "-----------------Notice Board Display------------------\n";
            n1.flightDisplay();
            n++;
        }
        catch (ApplicationException &ab) {
            ab.printException();
        }
    }
    else {
        cout << "Unable enter the Airport" << endl;
    }

    //------------- Passenger 3 Flow -------------
    cout << "------------------------" << endl;
    cout << "Passenger 3 Details:\n";
    p3.printPassengers();
    cout << "--------------------------\n";
    cout << "Airport Security for Checking Passport of Passengers " << endl;
    cout << "Check if passport is present " << endl;
    cin >> f;
    if (f == "yes" || f == "Yes") {
        try {
            a1.printAirport();
            cout << "Ticket Booking Employee\n";
            e1[1]->printEmployee();

            // Setup bank account for Passenger 3.
            p3.b2 = new BankAccount(809455, 1000);
            CreditCard ca3(14588674156952, "8-3-2056", "regular", 30000, 26000);
            DebitCard da3(145885125485, "28-2-2030", "business", 1000);
            p3.ticketBook(t1, ca3, da3);
            cout << endl;

            // Display the notice board.
            NoticeBoard n1;
            n1.f1[0] = new Flight("AIR001", "Air India", 300, "11:30", "12:00", "Delhi");
            n1.f1[1] = new Flight("AIR002", "Indigo Airlines", 250, "10:00", "11:00", "America");
            n1.f1[2] = new Flight("AIR023", "Qatar Airlines", 350, "14:10", "15:00", "Dubai");
            n1.f1[3] = new Flight("AIR056", "Air Asia Airlines", 260, "12:00", "13:00", "Nepal");
            n1.f1[4] = new Flight("AIR002", "Emirates Airlines", 300, "19:19", "20:00", "Srilanka");
            cout << "-----------------Notice Board Display------------------\n";
            n1.flightDisplay();
            n++;
        }
        catch (ApplicationException &ab) {
            ab.printException();
        }
    }
    else {
        cout << "Unable enter the Airport" << endl;
    }

    // Print the total number of seats booked.
    cout << endl << "Number of seats booked =" << n << endl;

    return 0;
}

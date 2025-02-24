# Detailed Explanation of Resume Points

## 1. Utilized try-catch blocks for robust and fault-tolerant error handling
- **Explanation:**  
  In the project, try-catch blocks are used to capture and manage exceptions during critical operations, such as payment processing and ticket booking. This ensures that if an error occurs (e.g., insufficient funds or a failed transaction), the system can handle it gracefully without crashing, thereby enhancing the reliability and stability of the application.

## 2. Implemented Strategy and State design patterns to achieve modularity and scalability
- **Strategy Pattern:**  
  The payment processing module uses the Strategy pattern by defining an abstract payment interface with concrete implementations for credit card, debit card, and net banking. This design allows the system to select the appropriate payment method dynamically at runtime without modifying the core booking logic.
  
- **State Pattern:**  
  The booking process leverages the State pattern by encapsulating booking statuses (such as processing, confirmed, and aborted) in separate classes. This makes it easier to manage and extend the booking process while keeping the code modular and scalable.

## 3. Enforced encapsulation through private constructors and controlled attribute access
- **Explanation:**  
  The project follows the object-oriented principle of encapsulation by restricting direct access to internal data. Private constructors and controlled attribute access ensure that objects are instantiated and modified only through well-defined interfaces. This not only protects the internal state but also results in a cleaner and more maintainable codebase.

## 4. Developed a comprehensive C++ Airport Reservation System simulating real-world functionalities
- **Explanation:**  
  The system simulates a full airport operation, including passenger verification, flight scheduling, ticket booking, and the display of flight information on a notice board. It integrates multiple modules such as flights, employees, passengers, and payment systems, showcasing the ability to translate real-world processes into a functional C++ application.

## 5. Integrated dynamic multi-channel payment processing to support credit card, debit card, and net banking transactions
- **Explanation:**  
  The payment module is designed to handle multiple payment channels dynamically. It supports transactions via credit cards, debit cards, and net banking, each with its own set of validations (e.g., checking for sufficient funds or credit limits). This flexible approach mirrors real-world payment systems and demonstrates the capability to integrate complex business logic efficiently.








#### ⦁	The Airport Employee checks the passenger’s passport.
#### ⦁	Passenger books a ticket for the flight.
#### ⦁	Ticket Counter displays temporary ticket details. 
#### ⦁	Ticket Counter provides the passenger with the options for different classes of tickets.
#### ⦁	Ticket Counter displays the status of the ticket booking.
#### ⦁	Passenger is provided with options for the type of payment methods whether it is credit card, debit card or netbanking.
#### ⦁	If the credit card amount reaches max limit then the payment is rejected. 
#### ⦁	It checks the balance in the bank account for payment and then proceeds to the next step based on the payment.
#### ⦁	Check the number of luggage to see if additional charges are required based on weight.
#### ⦁	The notice board displays the details of the flight.

#### State Pattern:
The booking process employs an abstract BookingStatus class with specific states—Processing, Confirm, and Aborted. This encapsulates the booking state and allows the system to change its behavior based on the current status.

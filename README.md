# DSA Project: Bank Account Management System

This project is a modular bank account management system implemented in C. It demonstrates the use of data structures such as hash tables, linked lists, and queues to manage bank accounts and their transaction histories.

## Features

- **Create Account:** Input personal details, deposit initial amount, and get a unique account number.
- **Display Account:** View details of any account by providing its account number.
- **Process Transactions:** Deposit or withdraw money, with all transactions recorded in a queue.
- **Transaction History:** View all transactions performed on an account.
- **Hash Table Storage:** Accounts are stored in a hash table for efficient access.
- **File Persistence:** Save and load account data to/from binary files.
- **Modular Architecture:** Clean separation of concerns across multiple modules.

## Data Structures Used

- **Hash Table:** For storing and retrieving accounts efficiently.
- **Linked List:** For chaining accounts in case of hash collisions.
- **Queue (Linked List):** For maintaining transaction history per account.

## Project Structure

```
banking/
├── main.c              // UI and menu system
├── accounts.c          // Account management logic
├── transactions.c      // Transaction processing logic
├── storage.c           // File I/O operations
├── auth.c              // Authentication utilities
├── include/
│   ├── accounts.h      // Account structure and function declarations
│   ├── transactions.h  // Transaction structure and function declarations
│   ├── storage.h       // Storage function declarations
│   └── auth.h          // Authentication function declarations
├── Makefile           // Build configuration
└── README.md          // Documentation
```

## How to Build & Run

### Prerequisites

- GCC or any standard C compiler
- Make utility

### Build

```bash
cd banking
make
```

### Run

```bash
./banking_system
# or
make run
```

## Usage

On running the program, you'll be presented with a menu:

1. **Create an account**
2. **Display account details**
3. **Perform Transactions**
4. **Save & Exit**

Follow the prompts to input details and perform actions. The system now automatically saves data to a binary file (`accounts.dat`) for persistence across program runs.

## Module Descriptions

### Core Modules

- **`main.c`**: Contains the user interface and menu system
- **`accounts.c`**: Handles account creation, management, and display
- **`transactions.c`**: Manages transaction processing and queue operations
- **`storage.c`**: Handles file I/O for data persistence
- **`auth.c`**: Provides authentication and validation utilities

### Header Files

- **`accounts.h`**: Account structure definitions and function declarations
- **`transactions.h`**: Transaction structure and processing function declarations
- **`storage.h`**: File I/O function declarations
- **`auth.h`**: Authentication function declarations

## Example Interaction

```
Enter your choice: 1.Create an account 2.Display account details 3.Perform Transactions 4.Save & Exit 
1
Enter account holder name: Alice
Enter deposited amount: 1000
Enter account type: Savings
Enter account holder phone number: 1234567890
Enter account holder age: 30
Enter account holder address: Wonderland
Your account has been created successfully!! Your account number is: 1001
```

## Improvements from Original

- **Modular Design**: Code is now split into logical modules for better maintainability
- **Data Persistence**: Account data is saved to and loaded from binary files
- **Better Organization**: Header files provide clear interfaces between modules
- **Build System**: Makefile for easy compilation and project management
- **Enhanced Authentication**: Separate module for user validation and account number generation

## Limitations

- Maximum 100 accounts supported (configurable in `accounts.h`)
- Basic validation; not suitable for production use without additional security measures
- Transaction history is not persisted across program restarts (only account data)

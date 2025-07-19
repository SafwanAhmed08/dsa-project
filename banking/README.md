# Banking System

A modular banking system implementation in C with hash table-based account storage and transaction queue management.

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
└── README.md          // This file
```

## Features

- **Account Management**: Create, find, and display bank accounts
- **Transaction Processing**: Handle deposits and withdrawals with queue-based transaction history
- **Hash Table Storage**: Efficient account lookup using hash table with collision handling
- **File Persistence**: Save and load account data to/from binary files
- **Authentication**: Basic account validation and authentication
- **Modular Design**: Clean separation of concerns across multiple modules

## Building and Running

### Prerequisites
- GCC compiler
- Make utility

### Build
```bash
cd banking
make
```

### Run
```bash
make run
```

### Clean
```bash
make clean
```

## Usage

1. **Create Account**: Register a new bank account with personal details
2. **Display Account**: View account details and transaction history
3. **Process Transactions**: Perform deposits and withdrawals
4. **Save & Exit**: Save all data and exit the program

## Data Structures

- **Hash Table**: Used for efficient account storage and retrieval
- **Linked List**: Used for collision resolution in hash table
- **Queue**: Used for transaction history management

## File Format

Account data is stored in binary format in `accounts.dat` file for persistence across program runs.

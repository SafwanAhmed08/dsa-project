---

# DSA Project: Bank Account Management System

This project is a simple bank account management system implemented in C. It demonstrates the use of data structures such as hash tables, linked lists, and queues to manage bank accounts and their transaction histories.

## Features

- **Create Account:** Input personal details, deposit initial amount, and get a unique account number.
- **Display Account:** View details of any account by providing its account number.
- **Process Transactions:** Deposit or withdraw money, with all transactions recorded in a queue.
- **Transaction History:** View all transactions performed on an account.
- **Hash Table Storage:** Accounts are stored in a hash table for efficient access.

## Data Structures Used

- **Hash Table:** For storing and retrieving accounts efficiently.
- **Linked List:** For chaining accounts in case of hash collisions.
- **Queue (Linked List):** For maintaining transaction history per account.

## How to Build & Run

### Prerequisites

- GCC or any standard C compiler
- Make (optional)

### Build

```bash
gcc -o bank_system project.c
```

### Run

```bash
./bank_system
```

## Usage

On running the program, you'll be presented with a menu:

1. **Create an account**
2. **Display account details**
3. **Perform Transactions**
5. **Exit**

Follow the prompts to input details and perform actions.

## File Structure

- `project.c` — Main source code containing all logic.

## Example Interaction

```
Enter your choice: 1.Create an account 2.Display account details 3.Perform Transactions 5.Exit 
1
Enter account holder name: Alice
Enter deposited amount: 1000
Enter account type: Savings
Enter account holder phone number: 1234567890
Enter account holder age: 30
Enter account holder address: Wonderland
Your account has been created successfully!! Your account number is, 1001
```

## Limitations

- Maximum 100 accounts supported.
- No persistent storage (data lost on exit).
- Basic validation; not suitable for production use.

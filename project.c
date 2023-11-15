#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ACCOUNTS 100
#define HASH_TABLE_SIZE 101

struct Transaction {
    char type; // 'D' for deposit, 'W' for withdrawal
    double amount;
    struct Transaction* next;
};

// Structure to represent a bank account
typedef struct Account{
    int acc_no,age;
    char name[50];
    double balance;
    long int phone;
    char acc_type[10];
    char address[60];
    struct Transaction* transactions;
    struct Account* next;
}acct;

// Hash table to store bank accounts
acct* hashTable[HASH_TABLE_SIZE];

// Function to calculate the hash value for an account number
int hashFunction(int acc_no) {
    return acc_no % HASH_TABLE_SIZE;
}

// Function to create a new bank account
acct* createAccount(int acc_no, const char* name, double balance,const char* address,int age,int phone,const char* acc_type) {
    acct* newAccount = (acct*)malloc(sizeof(acct));
    newAccount->acc_no = acc_no;
    newAccount->age = age;
    strncpy(newAccount->name, name, sizeof(newAccount->name));
    newAccount->balance = balance;
    newAccount->phone = phone;
    strncpy(newAccount->acc_type, acc_type, sizeof(newAccount->acc_type));
    strncpy(newAccount->address, address, sizeof(newAccount->address));
    newAccount->next = NULL;
    newAccount->transactions = NULL;
    return newAccount;
}

// Function to insert a bank account into the hash table
void insertAccount(acct* account) {
    int index = hashFunction(account->acc_no);
    // Handle collisions by chaining
    if (hashTable[index] == NULL) {
        hashTable[index] = account;
    } else {
        acct* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = account;
    }
}

// Function to find a bank account by account number
acct* findAccount(int acc_no) {
    int index = hashFunction(acc_no);
    acct* current = hashTable[index];
    while (current != NULL) {
        if (current->acc_no == acc_no) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Account not found
}

// Function to display account details
void displayAccount(acct* account) {
    if (account != NULL) {
        printf("Account Number: %d\n", account->acc_no);
        printf("Account Holder: %s\n", account->name);
        printf("Age: %d\n", account->age);
        printf("Balance: %.2f\n", account->balance);
        printf("Phone: %d\n", account->phone);
        printf("Account Type: %s\n", account->acc_type);
        printf("Address: %s", account->address);
        printf("\n");
        printf("Transaction History:\n");
        struct Transaction* currentTransaction = account->transactions;
        while (currentTransaction != NULL) {
            printf("Type: %c, Amount: %.2f\n", currentTransaction->type, currentTransaction->amount);
            currentTransaction = currentTransaction->next;
        }
        printf("\n");
    } else {
        printf("Account not found.\n\n");
    }
}

// Function to create a new transaction
struct Transaction* createTransaction(char type, double amount) {
    struct Transaction* newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    newTransaction->type = type;
    newTransaction->amount = amount;
    newTransaction->next = NULL;
    return newTransaction;
}

// Function to enqueue a transaction
void enqueue(struct Transaction** front, struct Transaction** rear, char type, double amount) {
    struct Transaction* newTransaction = createTransaction(type, amount);
    if (*rear == NULL) {
        *front = *rear = newTransaction;
    } else {
        (*rear)->next = newTransaction;
        *rear = newTransaction;
    }
}

// Function to dequeue a transaction
struct Transaction* dequeue(struct Transaction** front, struct Transaction** rear) {
    if (*front == NULL) {
        return NULL;
    }
    struct Transaction* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    return temp;
}

void processTransactions(struct Account* account) {
    struct Transaction* front = NULL;
    struct Transaction* rear = NULL;

    // Example: Enqueue deposit and withdrawal transactions
    enqueue(&front, &rear, 'D', 1000.0);
    enqueue(&front, &rear, 'W', 500.0);
    enqueue(&front, &rear, 'D', 2000.0);

    // Process transactions
    while (front != NULL) {
        struct Transaction* currentTransaction = dequeue(&front, &rear);
        // Update account balance based on transaction type
        if (currentTransaction->type == 'D') {
            account->balance += currentTransaction->amount;
        } else if (currentTransaction->type == 'W') {
            account->balance -= currentTransaction->amount;
        }
        // Store the transaction in the account's transaction history
        currentTransaction->next = account->transactions;
        account->transactions = currentTransaction;
    }
}

int main() {
    // Example: Adding accounts to the bank
    insertAccount(createAccount(1001, "John Doe", 5000.0,
    "Bangalore",20,1234675891,"Savings"));
    acct* foundAccount = findAccount(1001);
    processTransactions(foundAccount);
    displayAccount(foundAccount);
    return 0;
}
#include "include/accounts.h"
#include "include/transactions.h"

// Hash table to store bank accounts
acct *hashTable[HASH_TABLE_SIZE];

// Function to calculate the hash value for an account number
int hashFunction(int acc_no)
{
    return acc_no % HASH_TABLE_SIZE;
}

acct *createAccount(int acc_no, const char *name, double balance, const char *address, int age, long long int phone, const char *acc_type)
{
    acct *newAccount = (acct *)malloc(sizeof(acct));
    newAccount->acc_no = acc_no;
    newAccount->age = age;
    strncpy(newAccount->name, name, sizeof(newAccount->name));
    newAccount->balance = balance;
    newAccount->phone = phone;
    strncpy(newAccount->acc_type, acc_type, sizeof(newAccount->acc_type));
    strncpy(newAccount->address, address, sizeof(newAccount->address));
    newAccount->next = NULL;
    newAccount->transactions = NULL;
    newAccount->transactions_rear = NULL;  // Initialize the rear pointer for the transactions queue
    return newAccount;
}

// Function to insert a bank account into the hash table
void insertAccount(acct *account)
{
    int index = hashFunction(account->acc_no);
    // Handle collisions by chaining
    if (hashTable[index] == NULL)
    {
        hashTable[index] = account;
    }
    else
    {
        acct *current = hashTable[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = account;
    }
}

// Function to find a bank account by account number
acct *findAccount(int acc_no)
{
    int index = hashFunction(acc_no);
    acct *current = hashTable[index];
    while (current != NULL)
    {
        if (current->acc_no == acc_no)
        {
            return current;
        }
        current = current->next;
    }
    return NULL; // Account not found
}

// Function to display account details
void displayAccount(acct *account)
{
    if (account != NULL)
    {
        printf("Account Number: %d\n", account->acc_no);
        printf("Account Holder: %s\n", account->name);
        printf("Age: %d\n", account->age);
        printf("Balance: %.2f\n", account->balance);
        printf("Phone: %lld\n", account->phone);
        printf("Account Type: %s\n", account->acc_type);
        printf("Address: %s", account->address);
        printf("\n");
        printf("Transaction History:\n");
        struct Transaction *currentTransaction = account->transactions;
        while (currentTransaction != NULL)
        {
            printf("Type: %c, Amount: %.2f\n", currentTransaction->type, currentTransaction->amount);
            currentTransaction = currentTransaction->next;
        }
        printf("\n");
    }
    else
    {
        printf("Account not found.\n\n");
    }
}

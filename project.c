#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ACCOUNTS 100
#define HASH_TABLE_SIZE 101

struct Transaction
{
    char type; // 'D' for deposit, 'W' for withdrawal
    double amount;
    struct Transaction *next;
};

// Structure to represent a bank account
typedef struct Account
{
    int acc_no, age;
    char name[500];
    double balance;
    long long int phone;
    char acc_type[10];
    char address[600];
    struct Transaction *transactions;
    struct Account *next;
} acct;

// Hash table to store bank accounts
acct *hashTable[HASH_TABLE_SIZE];

// Function to calculate the hash value for an account number
int hashFunction(int acc_no)
{
    return acc_no % HASH_TABLE_SIZE;
}

// Function to create a new bank account
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

// Function to create a new transaction
struct Transaction *createTransaction(char type, double amount)
{
    struct Transaction *newTransaction = (struct Transaction *)malloc(sizeof(struct Transaction));
    newTransaction->type = type;
    newTransaction->amount = amount;
    newTransaction->next = NULL;
    return newTransaction;
}

// Function to enqueue a transaction
void enqueue(struct Transaction **front, struct Transaction **rear, char type, double amount)
{
    struct Transaction *newTransaction = createTransaction(type, amount);
    if (*rear == NULL)
    {
        *front = *rear = newTransaction;
    }
    else
    {
        (*rear)->next = newTransaction;
        *rear = newTransaction;
    }
}

// Function to dequeue a transaction
struct Transaction *dequeue(struct Transaction **front, struct Transaction **rear)
{
    if (*front == NULL)
    {
        return NULL;
    }
    struct Transaction *temp = *front;
    *front = (*front)->next;
    if (*front == NULL)
    {
        *rear = NULL;
    }
    return temp;
}

void processTransactions(acct *account, char type, double amount)
{
    // Create a new transaction
    struct Transaction *newTransaction = createTransaction(type, amount);

    // Check if withdrawal amount is greater than balance
    if (type == 'W' && amount > account->balance)
    {
        printf("Transaction failed. Not enough balance.\n");
        free(newTransaction); // Free memory allocated for the transaction
        return;
    }

    // Update account balance based on transaction type
    if (type == 'D')
    {
        account->balance += amount;
    }
    else if (type == 'W')
    {
        account->balance -= amount;
    }

    // Store the transaction in the account's transaction history
    newTransaction->next = account->transactions;
    account->transactions = newTransaction;
}

int main()
{
    int acc_no, age;
    long long int phone;
    char name[50], address[60], acc_type[10];
    double balance;
    int choice;
    int numbers = 1001;
    do
    {
        printf("Enter your choice: 1.Create an account 2.Display account details 3.Perform Transactions 5.Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Read account details from user input
            {
                printf("Enter account holder name: ");
                /*fix issue*/ scanf("%s", name);
                fflush(stdin);
                printf("Enter deposited amount: ");
                scanf("%lf", &balance);
                printf("Enter account type: ");
                scanf("%s", acc_type);
                fflush(stdin);
                printf("Enter account holder phone number: ");
                scanf("%lld", &phone);
                printf("Enter account holder age: ");
                scanf("%d", &age);
                fflush(stdin);
                printf("Enter account holder address: ");
                scanf(" %s", address);
                acct *newAccount = createAccount(numbers, name, balance, address, age, phone, acc_type);
                insertAccount(newAccount);
                printf("Your account has been created successfully!!\nYour account number is, %d \n", numbers);
                numbers++;
                break;
            }
        case 2:
        {
            printf("Enter the account number you want to view: ");
            scanf("%d", &acc_no);
            acct *account = findAccount(acc_no);
            if (account != NULL)
            {
                displayAccount(account);
            }
            else
            {
                printf("Account not found.\n\n");
            }
            break;
        }
        case 3:
        {
            printf("Enter the account number for which you want to process transactions: ");
            scanf("%d", &acc_no);
            acct *account = findAccount(acc_no);
            if (account != NULL)
            {
                char transactionType;
                double transactionAmount;

                // Accept input for each transaction
                do
                {
                    printf("Enter transaction type ('D' for deposit, 'W' for withdrawal, 'E' to end): ");
                    scanf(" %c", &transactionType);

                    if (transactionType == 'E')
                    {
                        break;
                    }

                    printf("Enter transaction amount: ");
                    scanf("%lf", &transactionAmount);

                    processTransactions(account, transactionType, transactionAmount);
                } while (1); // Loop until 'E' (end) is entered

                printf("Transactions processed successfully.\n");
            }
            else
            {
                printf("Account not found.\n\n");
            }
            break;
        }
        default:
            break;
        }
    } while (choice != 5);
}
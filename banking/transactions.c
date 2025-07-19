#include "include/transactions.h"
#include "include/accounts.h"

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

void processTransactions(struct Transaction **front, struct Transaction **rear, acct *account, char type, double amount)
{
    // Enqueue the new transaction
    enqueue(front, rear, type, amount);

    // Check if withdrawal amount is greater than balance
    if ((type == 'W'||type == 'w') && amount > account->balance)
    {
        printf("Transaction failed. Not enough balance.\n");
        return;
    }

    // Update account balance based on transaction type
    if (type == 'D'||type == 'd')
    {
        account->balance += amount;
    }
    else if (type == 'W'||type == 'w')
    {
        account->balance -= amount;
    }
    else{
        printf("Incorrect type chosen");
    }
}

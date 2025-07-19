#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "accounts.h"

// Transaction structure
struct Transaction
{
    char type; // 'D' for deposit, 'W' for withdrawal
    double amount;
    struct Transaction *next;
};

// Function declarations
struct Transaction *createTransaction(char type, double amount);
void enqueue(struct Transaction **front, struct Transaction **rear, char type, double amount);
struct Transaction *dequeue(struct Transaction **front, struct Transaction **rear);
void processTransactions(struct Transaction **front, struct Transaction **rear, acct *account, char type, double amount);

#endif

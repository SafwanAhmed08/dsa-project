#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ACCOUNTS 100
#define HASH_TABLE_SIZE 101

// Forward declaration
struct Transaction;

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
    struct Transaction *transactions_rear;  // Rear pointer for the transactions queue
    struct Account *next;
} acct;

// Hash table to store bank accounts
extern acct *hashTable[HASH_TABLE_SIZE];

// Function declarations
int hashFunction(int acc_no);
acct *createAccount(int acc_no, const char *name, double balance, const char *address, int age, long long int phone, const char *acc_type);
void insertAccount(acct *account);
acct *findAccount(int acc_no);
void displayAccount(acct *account);

#endif

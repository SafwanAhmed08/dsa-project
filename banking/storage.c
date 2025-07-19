#include "include/storage.h"
#include "include/accounts.h"

// Initialize hash table with NULL values
void initializeHashTable()
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
}

// Function to save all accounts to a file
void saveAccountsToFile(const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        acct *current = hashTable[i];
        while (current != NULL)
        {
            fwrite(current, sizeof(acct), 1, file);
            current = current->next;
        }
    }

    fclose(file);
    printf("Accounts saved successfully.\n");
}

// Function to load accounts from a file
void loadAccountsFromFile(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("No existing data file found. Starting fresh.\n");
        return;
    }

    acct tempAccount;
    while (fread(&tempAccount, sizeof(acct), 1, file) == 1)
    {
        acct *newAccount = createAccount(
            tempAccount.acc_no,
            tempAccount.name,
            tempAccount.balance,
            tempAccount.address,
            tempAccount.age,
            tempAccount.phone,
            tempAccount.acc_type
        );
        
        // Reset pointers since they won't be valid after loading
        newAccount->transactions = NULL;
        newAccount->transactions_rear = NULL;
        newAccount->next = NULL;
        
        insertAccount(newAccount);
    }

    fclose(file);
    printf("Accounts loaded successfully.\n");
}

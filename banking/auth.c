#include "include/auth.h"
#include "include/accounts.h"

static int nextAccountNumber = 1001;

// Function to validate if an account number is in valid format
bool validateAccountNumber(int acc_no)
{
    return acc_no >= 1001 && acc_no <= 999999;
}

// Function to authenticate a user (basic implementation)
bool authenticateUser(int acc_no, const char *name)
{
    acct *account = findAccount(acc_no);
    if (account != NULL && strcmp(account->name, name) == 0)
    {
        return true;
    }
    return false;
}

// Function to generate a new account number
int generateAccountNumber()
{
    return nextAccountNumber++;
}

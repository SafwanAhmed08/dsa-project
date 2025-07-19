#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>

// Function declarations for authentication
bool validateAccountNumber(int acc_no);
bool authenticateUser(int acc_no, const char *name);
int generateAccountNumber();

#endif

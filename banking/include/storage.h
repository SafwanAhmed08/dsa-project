#ifndef STORAGE_H
#define STORAGE_H

#include "accounts.h"

// Function declarations for file I/O operations
void saveAccountsToFile(const char *filename);
void loadAccountsFromFile(const char *filename);
void initializeHashTable();

#endif

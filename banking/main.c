#include "include/accounts.h"
#include "include/transactions.h"
#include "include/storage.h"
#include "include/auth.h"

int main()
{
    int acc_no, age;
    long long int phone;
    char name[50], address[60], acc_type[10];
    double balance;
    int choice;

    // Initialize the hash table and load existing data
    initializeHashTable();
    loadAccountsFromFile("accounts.dat");

    do
    {
        printf("Enter your choice: 1.Create an account 2.Display account details 3.Perform Transactions 4.Save & Exit \n");
        scanf("%d", &choice);
        while ((getchar()) != '\n');
        
        switch (choice)
        {
        case 1:
            // Read account details from user input
            {
                printf("Enter account holder name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter deposited amount: ");
                scanf("%lf", &balance);
                printf("Enter account type: ");
                scanf("%s", acc_type);
                while ((getchar()) != '\n');
                printf("Enter account holder phone number: ");
                scanf("%lld", &phone);
                printf("Enter account holder age: ");
                scanf("%d", &age);
                while ((getchar()) != '\n');
                printf("Enter account holder address: ");
                scanf("%[^\n]s", address);
                while ((getchar()) != '\n');

                // Generate a new account number
                int newAccNo = generateAccountNumber();

                // Create a new account
                acct *newAccount = createAccount(newAccNo, name, balance, address, age, phone, acc_type);

                // Initialize front and rear pointers for transactions queue
                struct Transaction *front = NULL;
                struct Transaction *rear = NULL;

                // Set the transaction queue pointers in the account structure
                newAccount->transactions = front;
                newAccount->transactions_rear = rear;

                // Insert the account into the system
                insertAccount(newAccount);

                printf("Your account has been created successfully!!\nYour account number is: %d \n", newAccNo);
                break;
            }
        case 2:
            // Display account details
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
            // Process transactions
            {
                printf("Enter the account number for which you want to process transactions: ");
                scanf("%d", &acc_no);
                acct *account = findAccount(acc_no);
                if (account != NULL)
                {
                    printf("Welcome %s\n", account->name);
                    char transactionType;
                    double transactionAmount;

                    // Accept input for each transaction
                    do
                    {
                        printf("Enter transaction type ('D' for deposit, 'W' for withdrawal, 'E' to end): ");
                        scanf(" %c", &transactionType);

                        if (transactionType == 'E' || transactionType == 'e')
                        {
                            break;
                        }

                        printf("Enter transaction amount: ");
                        scanf("%lf", &transactionAmount);

                        // Process transactions using the queue-based approach
                        processTransactions(&(account->transactions), &(account->transactions_rear), account, transactionType, transactionAmount);

                    } while (1); // Loop until 'E' (end) is entered

                    printf("Transactions processed successfully.\n");
                }
                else
                {
                    printf("Account not found.\n\n");
                }
                break;
            }
        case 4:
            // Save and exit
            saveAccountsToFile("accounts.dat");
            printf("Data saved. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}

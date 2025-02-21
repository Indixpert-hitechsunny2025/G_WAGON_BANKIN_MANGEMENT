#include <stdio.h>
#include <string.h>

char name[50], accountNumber[12];
float balance = 0;
int accountCreated = 0;

int isValidName(char name[]) {
    for (int i = 0; i < strlen(name); i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' ')) {
            return 0;
        }
    }
    return 1; 
}

int isValidNumber(char input[]) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0; 
        }
    }
    return 1;
}

float convertToFloat(char input[]) {
    float result = 0;
    int i = 0;
    
    while (input[i] != '\0') {
        result = result * 10 + (input[i] - '0'); 
        i++;
    }
    
    return result;
}

void createAccount() {
    char input[50];

    do {
        printf("Enter Name (Only Letters): ");
        scanf(" %[^\n]s", name);
        if (!isValidName(name))
            printf("Invalid Name! Use only letters and spaces.\n");
    } while (!isValidName(name));

    do {
        printf("Enter 11-digit Account Number: ");
        scanf("%s", accountNumber);
        if (strlen(accountNumber) != 11 || !isValidNumber(accountNumber))
            printf("Invalid Account Number! Must be 11 digits.\n");
    } while (strlen(accountNumber) != 11 || !isValidNumber(accountNumber));

    do {
        printf("Enter Minimum Balance (500 or more): ");
        scanf("%s", input);
        if (!isValidNumber(input) || (balance = convertToFloat(input)) < 500) 
            printf("Invalid! Balance must be 500 or more.\n");
    } while (!isValidNumber(input) || balance < 500);

    accountCreated = 1;
    printf("Account Created Successfully!\n");
}

void depositAmount() {
    if (!accountCreated) {
        printf("Create an account first!\n");
        return;
    }

    char input[50];
    float amount;

    do {
        printf("Enter Amount to Deposit (Min 100): ");
        scanf("%s", input);
        if (!isValidNumber(input) || (amount = convertToFloat(input)) < 100)
            printf("Invalid! Minimum deposit is 100.\n");
    } while (!isValidNumber(input) || amount < 100);

    balance += amount;
    printf("%.2f Deposited Successfully!\n", amount);
}

void withdrawAmount() {
    if (!accountCreated) {
        printf("Create an account first!\n");
        return;
    }

    char input[50];
    float amount;

    do {
        printf("Enter Amount to Withdraw: ");
        scanf("%s", input);
        if (!isValidNumber(input) || (amount = convertToFloat(input)) > (balance - 500))
            printf("Invalid! Minimum balance 500 must be maintained.\n");
    } while (!isValidNumber(input) || amount > (balance - 500));

    balance -= amount;
    printf("%.2f Withdrawn Successfully!\n", amount);
}

void checkBalance() {
    if (!accountCreated) {
        printf("Create an account first!\n");
    } else {
        printf("Total Balance: %.2f\n", balance);
    }
}

void displayAccountDetails() {
    if (!accountCreated) {
        printf("Create an account first!\n");
    } else {
        printf("\nAccount Details:\nName: %s\nAccount No: %s\nBalance: %.2f\n", name, accountNumber, balance);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Display Account Details\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositAmount();
                break;
            case 3:
                withdrawAmount();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAccountDetails();
                break;
            case 0:
                printf("Exiting Program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }
}

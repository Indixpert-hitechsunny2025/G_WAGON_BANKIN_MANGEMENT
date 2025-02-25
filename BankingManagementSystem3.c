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
    int i = 0, dotCount = 0;
    if (input[0] == '\0') return 0;  

    while (input[i] != '\0') {
        if (input[i] == '.') {
            dotCount++;
            if (dotCount > 1) return 0;  
        } else if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

float convertToFloat(char input[]) {
    float value;
    sscanf(input, "%f", &value);
    return value;
}

int isValidTransactionAmount(float amount) {
    return (amount == 100 || amount == 200 || amount == 500);
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
        printf("Enter Amount to Deposit (Only 100, 200, or 500 Notes Allowed): ");
        scanf("%s", input);
        amount = convertToFloat(input);
        if (!isValidNumber(input) || !isValidTransactionAmount(amount))
            printf("Invalid! Deposit amount must be 100, 200, or 500 only.\n");
    } while (!isValidNumber(input) || !isValidTransactionAmount(amount));

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
        printf("Enter Amount to Withdraw (Only 100, 200, 500 Notes Allowed): ");
        scanf("%s", input);
        amount = convertToFloat(input);
        
        if (!isValidNumber(input) || amount > (balance - 500) || !isValidTransactionAmount(amount)) {
            printf("Invalid! Enter an amount using only 100, 200, or 500 notes while maintaining a minimum balance of 500.\n");
        }
    } while (!isValidNumber(input) || amount > (balance - 500) || !isValidTransactionAmount(amount));

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

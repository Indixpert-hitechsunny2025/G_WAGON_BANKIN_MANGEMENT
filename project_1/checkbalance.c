#include <stdio.h>
#include <string.h>

char name[50],accountNumber[12];
float balance = 0;
int accountCreated = 0;

int option(int);
void createAccount();
void depositAmount();
void withdrawAmount();
void checkBalance();
int isValidName(char name[]);
int isValidNumber(char input[]);
float convertToFloat(char input[]);
int validateTaskNumber(int task);

int main() {
    int choice;

    while (1) {
        printf("\n***** Simple Banking System *****\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("0. Exit");
        printf("\n==============================\n");
        printf("Enter your choice:- ");
        if (scanf("%d", &choice) != 1 || !validateTaskNumber(choice)) {
            printf("\nInvalid input! Please enter a number between 0 and 5.\n");
            while (getchar() != '\n');
            continue;
        }
        if (choice == 0) {
            printf("\nExiting Program. Goodbye!\n");
            break;
        }
        option(choice);
    }
    return 0;
}

int option(int choice){
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
        case 0:
            printf("\nExiting Program. Goodbye!\n");
            return 0;
        default:
            printf("\nInvalid Choice! Try Again.\n");
    }
}

void createAccount() {
    char input[50];
    do {
        printf("Enter 11-digit Account Number:- ");
        scanf("%s", accountNumber);
        if (strlen(accountNumber) != 11 || !isValidNumber(accountNumber))
            printf("\nInvalid Account Number! Must be 11 digits.\n");
    } while (strlen(accountNumber) != 11 || !isValidNumber(accountNumber));
    
    do {
        printf("Enter Name (Only Letters):- ");
        scanf(" %[^\n]s", name);
        if (!isValidName(name))
            printf("\nInvalid Name! Use only letters and spaces.\n");
    } while (!isValidName(name));
        
    do {
        printf("Opning Balance (500 or more):- ");
        scanf("%s", input);
        if (!isValidNumber(input) || (balance = convertToFloat(input)) < 500) 
            printf("\nInvalid! Balance must be 500 or more.\n");
    } while (!isValidNumber(input) || balance < 500);
    
    accountCreated = 1;
        printf("\n*****Successfully created account*****\n");
        printf("\nAccount number:- %s\n", accountNumber);
        printf("Account name:- %s\n", name);
        printf("Deposit amount:- %.2f\n", balance);
        printf("\n==============================\n");
}

void depositAmount() {
    if (!accountCreated) {
        printf("Create an account first!\n");
        return;
    }

    char input[50];
    float amount;

    do {
        printf("\nEnter Amount to Deposit:- ");
        scanf("%s", input);
        if (!isValidNumber(input) || (amount = convertToFloat(input)) < 0)
            printf("\nInvalid! Minimum deposit is 100.\n");
    } while (!isValidNumber(input) || amount < 0);

    balance += amount;
        printf("\n***** Deposit successful. *****\n");
        printf("\nAccount number:- %s\n", accountNumber);
        printf("New Balance:- %.2f\n", balance);
        printf("\n==============================\n");
}

void withdrawAmount() {
    if (!accountCreated) {
        printf("Create an account first!\n");
        return;
    }

    char input[50];
    float amount;

    do {
        printf("\nEnter Amount to Withdraw: ");
        scanf("%s", input);
        if (!isValidNumber(input) || (amount = convertToFloat(input)) > (balance - 500)){
            printf("\nInvalid! Minimum balance 500 must be maintained.\n");
            continue;
        }
        if (((int)amount) % 100 != 0) {
            printf("\nError: Withdrawal amount must be a round figure\n");
            amount = -1;
        }
    } while (!isValidNumber(input) || amount > (balance - 500));
    if(amount > 0){
        balance -= amount;
        printf("\n***** Withdrawal successful! *****\n");
        printf("\nAccount number:- %s\n", accountNumber);
        printf("Your new balance is:- %.2f\n", balance);
        printf("\n==============================\n");
    }
}

void checkBalance() {
    if (!accountCreated) {
        printf("Create an account first!\n");
    } else {
        printf("\n***** Current Balance *****\n");
        printf("\nAccount number:- %s\n", accountNumber);
        printf("Your current balance is:- %.2f\n", balance);
        printf("\n==============================\n");
    }
}
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

int validateTaskNumber(int task) {
    return task >= 0 && task <= 5;
}
#include <stdio.h>
#include <string.h>

int created = 0;
char holderName[20];
int accountnumber;
float balance = 0;

void createAccount() {
    printf("\nEnter account holder name: ");
    getchar();
    scanf("%[^\n]s", holderName);
    
    printf("Enter Account Number: ");
    scanf("%d", &accountnumber);
    
    balance = 0;
    created = 1;

    printf("\nAccount created successfully!\n");
}

void deposit() {
    if (created == 0) {
        printf("\nNo account found! Please create an account first.\n");
        return;
    }

    float depositAmount;
    printf("Enter deposit amount: ");
    scanf("%f", &depositAmount);

    if (depositAmount >= 100) {
        balance += depositAmount;
        printf("Deposit successful!\n");
        printf("Your current balance: %.2f\n", balance);
    } else {
        printf("Deposit amount must be at least 100.\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n***** BANK MENU *****\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                printf("\nThank you for using our banking system!\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
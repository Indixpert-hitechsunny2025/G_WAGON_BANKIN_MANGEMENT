#include <stdio.h>
#include <string.h>

void checkBalance(char accountNumber[]) {
    int balance = 5000;  // account balance
    
    if (strlen(accountNumber) != 11) {
        printf("Create an account first!\n");
    } else {
        printf("\n***** Current Balance *****\n");
        printf("Account number: %s\n", accountNumber);
        printf("Your current balance is: %d\n", balance);
        printf("\n==============================\n");
    }
}

int main() {
    char accountNumber[20];

    printf("Enter account number: ");
    scanf("%s", accountNumber);

    checkBalance(accountNumber);
    return 0;
}
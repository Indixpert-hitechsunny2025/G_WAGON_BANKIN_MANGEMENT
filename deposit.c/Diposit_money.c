#include <stdio.h>

void deposit(float *balance, float amount) {
    if (amount > 100) {
*balance += amount;
        printf("Deposit successful! Your new balance is: %.2f\n\n", *balance);
    } else {
        printf("Invalid deposit amount. Please enter a valid amount.\n\n");
    }
}

int main() {
    float balance;
    
    float amount;
    int choice;

    printf("Welcome to the our bank of india!\n");

    while (1) {
        printf("\t\t============*BANK OF INDIA*============\n\n");
        printf("Your current balance is: %.2f\n", balance);
        printf("please Enter the amount to deposit: ");
        scanf("%f", &amount);

        deposit(&balance, amount);

        printf("Do you want to deposit again? (1 for Yes, 2 for No): ");
        scanf("%d", &choice);
        
        
        

        if (choice == 0) {
            printf("Thank you for using the deposit system. Your final balance is: %.2f\n", balance);
            break;
            
        }
    }

    return 0;
}

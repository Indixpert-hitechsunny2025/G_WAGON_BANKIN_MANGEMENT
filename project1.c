#include <stdio.h>
#include <string.h>

int isDigits(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int createAccount(char firstName[], char lastName[], char accountNo[], float *initialBalance) {
    
    printf("Enter your first name: ");
    scanf("%s", firstName);

    
    printf("Enter your last name: ");
    scanf("%s", lastName);

     
     while (1) {
        printf("Enter your 11-digit account number: ");
        scanf("%s", accountNo);
        
        if (strlen(accountNo) != 11) {
            printf("Invalid account number. Please enter exactly 11 digits.\n");
        } else if (!isDigits(accountNo)) {
            printf("Invalid account number. Please enter digits only.\n");
        } else {
            break;
        }
    }

    
    while (1) {
        printf("Enter your initial balance (minimum 500): "); 
        scanf("%f", initialBalance);

        if (*initialBalance < 500) {  
            printf("Initial balance must be at least 500.\n");
        } else {
            break;
        }
    }

    
    return 1;
}

int main() {
    char firstName[50];
    char lastName[50];
    char accountNo[12];
    float initialBalance;

    if (createAccount(firstName, lastName, accountNo, &initialBalance)) {  
        printf("\nAccount Created Successfully!\n");
        printf("--------------------------\n");
        printf("First Name: %s\n", firstName);
        printf("Last Name: %s\n", lastName);
        printf("Account Number: %s\n", accountNo);
        printf("Initial Balance: %.2f\n", initialBalance);
        printf("--------------------------\n");
    } else {
        printf("Account creation failed.\n"); 
    }

    return 0;
}













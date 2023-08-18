// Change Maker Program with Service Fee
// This program takes an input amount in dollars and cents, applies a service fee, and converts the remaining balance into coins of various denominations.

#define _CRT_SECURE_NO_WARNINGS // To suppress certain warnings related to scanf

#include <stdio.h>

int main(void)
{
    int coinCounter = 0, cent = 0;
    double serviceFee = 0.0, balanceToDispense = 0.0, enteredValue = 0.0;

    // Print program introduction
    printf("Change Maker Machine\n");
    printf("====================\n");
    printf("Enter dollars and cents amount to convert to coins: $");
    
    // Read the input amount from the user
    scanf("%lf", &enteredValue);
    
    // Calculate service fee
    serviceFee = (enteredValue + 0.005) * 0.05;
    
    // Display service fee
    printf("Service fee (5.0 percent): %.2lf\n", serviceFee);
    
    // Calculate balance to dispense
    balanceToDispense = enteredValue - serviceFee;
    
    // Display balance to dispense
    printf("Balance to dispense: $%.2lf\n", balanceToDispense);
    printf("\n");
    
    // Convert remaining balance into cents
    cent = balanceToDispense * 100;
    
    // Calculate and display coin quantities
    coinCounter = cent / 200;
    cent = cent % 200;
    printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", coinCounter, (double)cent / 100);
    
    coinCounter = cent / 100;
    cent = cent % 100;
    printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", coinCounter, (double)cent / 100);
    
    coinCounter = cent / 25;
    cent = cent % 25;
    printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", coinCounter, (double)cent / 100);
    
    coinCounter = cent / 10;
    cent = cent % 10;
    printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", coinCounter, (double)cent / 100);
    
    coinCounter = cent / 5;
    cent = cent % 5;
    printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", coinCounter, (double)cent / 100);
    
    coinCounter = cent / 1;
    cent = cent % 1;
    printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", coinCounter, (double)cent / 100);
    printf("\n");
    
    // Display completion message
    printf("All coins dispensed!\n");

    return 0;
}

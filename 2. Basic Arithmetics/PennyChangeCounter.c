// Change Maker Program
// This program takes an input amount in dollars and cents and converts it into coins (toonies, loonies, quarters).

#define _CRT_SECURE_NO_WARNINGS // To suppress certain warnings related to scanf

#include <stdio.h>

int main(void)
{
    // Initialize variables to store coin quantities and remaining values
    int quarter = 0, loonie = 0, toonie = 0, cents = 0;
    double amount = 0.0, remaining = 0.0, remainingCents = 0.0, lonniesRemaining = 0.0, quarterRemaining = 0.0;

    // Print program introduction
    printf("Change Maker Machine\n");
    printf("====================\n");
    printf("Enter dollars and cents amount to convert to coins: $");
    
    // Read the input amount from the user
    scanf("%lf", &amount);
    printf("\n");

    // Convert input amount into cents
    cents = (amount + 0.005) * 100;

    // Calculate the number of toonies and remaining cents
    toonie = cents / 200;
    remainingCents = cents % 200;

    // Calculate the number of loonies and remaining dollars
    remaining = remainingCents / 100;
    loonie = remaining;

    // Calculate the number of quarters and remaining cents
    lonniesRemaining = remaining - loonie;
    quarter = lonniesRemaining / 0.25;
    quarterRemaining = lonniesRemaining - quarter * 0.25;

    // Display the calculated coin quantities and remaining amounts
    printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonie, remaining);
    printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonie, lonniesRemaining);
    printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarter, quarterRemaining);
    printf("\n");
    
    // Display a message about any remaining amount (due to rounding)
    printf("Machine error! Thank you for letting me keep $%.2lf!\n", quarterRemaining);

    return 0;
}

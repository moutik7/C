
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define minIncome 500.00
#define maxIncome 400000.00
#define minWish 1
#define maxWish 10
#define minValue 100.00


int main(void)
{
	double salary = 0.0, itemCost[maxWish], total = 0, priorityAmount = 0.0, month = 0;
	int wish, priority[maxWish], i, flag = 1, selection = 0, year = 0, monthRemaining = 0, financeCount = 0, prioritySelection = 0, priorityFinanceCount = 0;
	char financeOptions[maxWish];



	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &salary);

		if (salary > maxIncome)
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");

		if (salary < minIncome)
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");



	} while (salary > maxIncome || salary < minIncome);


	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &wish);

		if (wish > maxWish || wish < minWish)
			printf("ERROR: List is restricted to between 1 and 10 items.\n");


	} while (wish > maxWish || wish < minWish);

	for (i = 0;i < wish;i++)
	{
		printf("\nItem-%d Details:\n", i + 1);
		do
		{

			printf("   Item cost: $");
			scanf("%lf", &itemCost[i]);

			if (itemCost[i] < minValue)
				printf("      ERROR: Cost must be at least $100.00\n");
		} while (itemCost[i] < minValue);

		do
		{

			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);

			if (priority[i] < 1 || priority[i]>3)
				printf("      ERROR: Value must be between 1 and 3\n");
		} while (priority[i] < 1 || priority[i]>3);

		do
		{

			printf("   Does this item have financing options? [y/n]: ");
			scanf("%s", &financeOptions[i]);




			if (financeOptions[i] == 110 || financeOptions[i] == 121)  // ASCII VALUE are used for comparisson
			{
				flag = 0; // used to exit the loop if it is y or n
				financeCount = financeCount + 1;
			}
			else
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}

		} while (flag);



	}


	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0;i < wish;i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], (char)financeOptions[i], itemCost[i]);
		total += itemCost[i];

	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", total);

	flag = 1;

	do
	{
		printf("\nHow do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selection);


		if (selection == 1)
		{
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", total);
			
			month = (total) / salary;
			year = month / 12;
			monthRemaining = (int)month % 12;
			monthRemaining++;

			printf("Forecast: %d years, %d months\n", year, monthRemaining);

			if (financeCount != 0)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.");
			}
			printf("\n====================================================\n");



		}
		else if (selection == 2)
		{
			priorityAmount = 0;
                        priorityFinanceCount = 0;
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &prioritySelection);

			if (prioritySelection < 1 || prioritySelection>3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
			else
			{
                               
				for (i = 0;i < wish;i++) //loop for checking priority elements and adding their amount
				{
					if (priority[i] == prioritySelection)
					{
						priorityAmount = priorityAmount + itemCost[i];
						if (financeOptions[i] == 121)   //checking foy y in array 
						{
							priorityFinanceCount++;
						}
					}
				}

				printf("\n====================================================\n");
				printf("Filter:   by priority (%d)\n", prioritySelection);
				printf("Amount:   $%1.2lf\n", priorityAmount);
				
				month = (priorityAmount) / salary;  // calcuation of amount to be printed
				year = month / 12;
				monthRemaining =(int)month % 12;
				monthRemaining++;

				printf("Forecast: %d years, %d months\n", year, monthRemaining);

				if (priorityFinanceCount != 0)
				{
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
				}
				printf("====================================================\n");


			}




		}
		else if (selection == 0)
		{
			flag = 0;  // used to exit loop if user enters 0
		}
		else if (selection < 0 || selection > 2)
		{
			printf("\nERROR: Invalid menu selection.\n");
		}




	} while (flag);

	printf("\nBest of luck in all your future endeavours!");

	return 0;
}

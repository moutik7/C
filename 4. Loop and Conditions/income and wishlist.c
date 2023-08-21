
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define minIncome 500.00
#define maxIncome 400000.00
#define minWish 1
#define maxWish 10
#define minValue 100.00


int main(void)
{
	double salary = 0.0 , itemCost[maxWish],total=0;
	int wish, priority[maxWish],i,flag = 1;
	char financeOptions[maxWish];
	
	

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf",&salary);

		if (salary > maxIncome)
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");

		if (salary < minIncome)
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");

	

	} while (salary > maxIncome || salary < minIncome);


	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d",&wish);

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

			if (priority[i]<1 || priority[i]>3)
				printf("      ERROR: Value must be between 1 and 3\n");
		} while (priority[i] < 1 || priority[i]>3);

		do
		{
			
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%s", &financeOptions[i]);

			
			

			if (financeOptions[i] == 110 || financeOptions[i] == 121)
			{
				flag = 0;
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
		printf("%3d  %5d    %5c    %11.2lf\n", i+1, priority[i],(char)financeOptions[i], itemCost[i]);
		total += itemCost[i];

	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n",total);
        printf("Best of luck in all your future endeavours!");

	return 0;
}

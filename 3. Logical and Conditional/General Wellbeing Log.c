

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2010  // initialising for fixed values
#define MAX_YEAR 2021

int main(void)
{
	int const JAN = 1;   // intializing constants for fixed values
	int const DEC = 12;
	

	int inputMonth = 0, inputYear = 0;  //variables used to store values prompted bu user
	printf("General Well-being Log\n");
	printf("======================\n");

	do  // here do while loop is used because we do not have year and month for first iteration as do while loop is a exit control loop .in such consitions do while loop is useful.
	{
		

		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d",&inputYear,&inputMonth);

		if (inputYear < MIN_YEAR || inputYear > MAX_YEAR)   //here condition is checked for year
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			
			
		}

		if (inputMonth < JAN || inputMonth > DEC)  // here condition is checked for months
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
			
		}
		

		
		


	} while (inputYear < MIN_YEAR || inputYear > MAX_YEAR || inputMonth < JAN || inputMonth > DEC);

	printf("\n*** Log date set! ***\n");
	printf("\nLog starting date: ");
	switch (inputMonth)   // here switch case is used instead of if else as we have only 12 choices and it is easier to perform.
	{
	case 1:printf("%d-JAN-01",inputYear);
		break;
	case 2:printf("%d-FEB-01", inputYear);
		break;
	case 3:printf("%d-MAR-01", inputYear);
		break;
	case 4:printf("%d-APR-01", inputYear);
		break;
	case 5:printf("%d-MAY-01", inputYear);
		break;
	case 6:printf("%d-JUN-01", inputYear);
		break;
	case 7:printf("%d-JUL-01", inputYear);
		break;
	case 8:printf("%d-AUG-01", inputYear);
		break;
	case 9:printf("%d-SEP-01", inputYear);
		break;
	case 10:printf("%d-OCT-01", inputYear);
		break;
	case 11:printf("%d-NOV-01", inputYear);
		break;
	case 12:printf("%d-DEC-01", inputYear);
		break;

	}

	return 0;
}
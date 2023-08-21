

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2010  // initialising for fixed values
#define MAX_YEAR 2021
#define LOG_DAYS 3

int main(void)
{
	int const JAN = 1;   // intializing constants for fixed values
	int const DEC = 12;
	

	int inputMonth = 0, inputYear = 0,i = 0;  //variables used to store values prompted bu user
        double morng = 0.0,eveng = 0.0,sumMorng = 0.0, sumEveng = 0.0, sumTotal = 0.0, avgMorng = 0.0, avgEveng = 0.0, avgTotal =0.0;
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
	
	


       for(i=1;i<=LOG_DAYS;i++)
       {
        switch (inputMonth)   // here switch case is used instead of if else as we have only 12 choices and it is easier to perform.
	{
	case 1:printf("\n%d-JAN-%02d\n",inputYear,i);
		break;
	case 2:printf("\n%d-FEB-%02d\n",inputYear,i);
		break;
	case 3:printf("\n%d-MAR-%02d\n",inputYear,i);
		break;
	case 4:printf("\n%d-APR-%02d\n",inputYear,i);
		break;
	case 5:printf("\n%d-MAY-%02d\n",inputYear,i);
		break;
	case 6:printf("\n%d-JUN-%02d\n",inputYear,i);
		break;
	case 7:printf("\n%d-JUL-%02d\n",inputYear,i);
		break;
	case 8:printf("\n%d-AUG-%02d\n",inputYear,i);
		break;
	case 9:printf("\n%d-SEP-%02d\n",inputYear,i);
		break;
	case 10:printf("\n%d-OCT-%02d\n",inputYear,i);
		break;
	case 11:printf("\n%d-NOV-%02d\n",inputYear,i);
		break;
	case 12:printf("\n%d-DEC-%02d\n",inputYear,i);
		break;

	}
      
        
	
	do
	{
	 printf("   Morning rating (0.0-5.0): ");
	 scanf("%lf",&morng);

	  if(morng < 0.0 || morng > 5.0)
	  {
	    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

	  }
	} while(morng < 0.0 || morng > 5.0);




	do
	{
	 printf("   Evening rating (0.0-5.0): ");
	 scanf("%lf",&eveng);

	  if(eveng < 0.0 || eveng > 5.0)
	  {
	    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

	  }
	} while(eveng < 0.0 || eveng > 5.0);
	
	sumMorng+= morng;
	sumEveng+= eveng;
	sumTotal=sumMorng + sumEveng;
	avgMorng = sumMorng / LOG_DAYS;
	avgEveng = sumEveng / LOG_DAYS;
	avgTotal = (avgMorng + avgEveng)/2;
	}
     printf("\n");
     printf("Summary\n");
     printf("=======\n");
     printf("Morning total rating: %.3lf\n", sumMorng);
     printf("Evening total rating: %.3lf\n", sumEveng);
     printf("----------------------------\n");
     printf("Overall total rating: %.3lf\n\n", sumTotal);
     printf("Average morning rating:  %.1lf\n", avgMorng);
     printf("Average evening rating:  %.1lf\n", avgEveng);
     printf("----------------------------\n");
     printf("Average overall rating:  %.1lf\n", avgTotal);

    return 0;
}
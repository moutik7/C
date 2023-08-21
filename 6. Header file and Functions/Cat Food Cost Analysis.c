

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include "Cat Food Cost Analysis.h"

int getIntPositive(int* num)
{
	int val;
	do
	{
		scanf("%d", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (val <= 0);
	if (num != NULL)

		*num = val;
	return val;

}


double getDoublePositive(double* number)
{
	double value;
	do
	{
		scanf("%lf", &value);
		if (value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (value <= 0);
	if (number != NULL)

		*number = value;
	return value;//return the variable val

}



void openingMessage(const int requiredProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", requiredProducts);
	printf("NOTE: A 'serving' is %dg\n", TOTAL_GRAMS);
}



struct CatFoodInfo getCatFoodInfo(const int sequence_num)
{
	struct CatFoodInfo food = { 0 };
	printf("\nCat Food Product #%d\n", sequence_num);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.sku);
	printf("PRICE         : $");
	getDoublePositive(&food.productRate);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weightInLbs);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calories);

	return food;
}


void displayCatFoodHeader()
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}


void displayCatFoodData(const int sku, const double* rate, const int caloriesPerServe, const double* weight )
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *rate, *weight, caloriesPerServe);
}


void start()
{
	struct CatFoodInfo cats[MAXIMUM_PRODUCT] = { {0} };
	openingMessage(MAXIMUM_PRODUCT);
	int i;
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		cats[i] = getCatFoodInfo(i + 1);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		displayCatFoodData(cats[i].sku, &cats[i].productRate, cats[i].calories, &cats[i].weightInLbs);
	}
}

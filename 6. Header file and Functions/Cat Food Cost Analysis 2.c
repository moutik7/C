


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include "Cat Food Cost Analysis 2.h"

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
{printf("\n");
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}


void displayCatFoodData(const int sku, const double* rate, const int caloriesPerServe, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *rate, *weight, caloriesPerServe);
}



double convertLbsKg(const double* lbs, double* kg)
{
	double i;
	i = *lbs / KG_IN_LBS;
	if (kg != NULL)
	{
		*kg = i;
	}
	return(i);
}

int convertLbsG(const double* lbs, int* g)
{
	int j;
	j = convertLbsKg(lbs, 0) * 1000;
	if (g != NULL)
	{
		*g = j;
	}
	return(j);
}

void convertLbs(const double* lbs_convert, double* kg, int* g)
{
	convertLbsKg(lbs_convert, kg);
	convertLbsG(lbs_convert, g);
}


double calculateServings(const int volume, const int sum, double* result)
{
	double i;
	i = (double)sum / (double)volume;
	if (result != NULL)
	{
		*result = i;
	}
	return(i);
}


double calculateCostPerServing(const double* rate, const double* result, double* CostofResult)
{
	double cost = 0;
	cost = *rate / *result;
	if (CostofResult != NULL)
	{
		*CostofResult = cost;
	}
	return(cost);
}
//===============================End of Function 12======================================//
// Function 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double*
	CostCalories)
{
	double cost = 0;
	cost = *price / *calories;
	if (CostCalories != NULL)
	{
		*CostCalories = cost;
	}
	return(cost);
}


struct ReportData calculateReportData(const struct CatFoodInfo getDetailCatFood)
{
	struct ReportData reportinfo;
	double calo;
	// For SKU, RATE, Weight and Calories
	reportinfo.sku = getDetailCatFood.sku;
	reportinfo.productRate = getDetailCatFood.productRate;
	reportinfo.weightInLbs = getDetailCatFood.weightInLbs;
	reportinfo.calories = getDetailCatFood.calories;
	// For kg and g 
	reportinfo.kg = convertLbsKg(&getDetailCatFood.weightInLbs, &reportinfo.kg);
	reportinfo.g = convertLbsG(&getDetailCatFood.weightInLbs, &reportinfo.g);
	reportinfo.sumServe = calculateServings(TOTAL_GRAMS, reportinfo.g,&reportinfo.sumServe);
	reportinfo.perServe = calculateCostPerServing(&reportinfo.productRate,&reportinfo.sumServe, &reportinfo.perServe);
	calo = reportinfo.calories * reportinfo.sumServe;
	reportinfo.calPerServe = calculateCostPerCal(&reportinfo.productRate, &calo,&reportinfo.calPerServe);
	return(reportinfo);
}

void displayReportHeader(void)
{
	printf("\n");
	printf("Analysis Report (Note: Serving = %dg\n", TOTAL_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(const struct ReportData reportinfo, const int cheap)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
		reportinfo.sku, reportinfo.productRate, reportinfo.weightInLbs, reportinfo.kg, reportinfo.g,reportinfo.calories, reportinfo.sumServe, reportinfo.perServe,reportinfo.calPerServe);
}

void displayFinalAnalysis(const struct CatFoodInfo cheaper_product)
{
	printf("\n");
	printf("Final Analysis\n--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", cheaper_product.sku,cheaper_product.productRate);
	printf("Happy shopping!\n");
}

void start(void)
{
	struct CatFoodInfo catFoodDetail[MAXIMUM_PRODUCT] = { {0} };
	int i = 0, cheapproduct = 0;
	openingMessage(MAXIMUM_PRODUCT);
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		catFoodDetail[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		displayCatFoodData(catFoodDetail[i].sku, &catFoodDetail[i].productRate,
			catFoodDetail[i].calories, &catFoodDetail[i].weightInLbs);
	}
	struct ReportData reportArray[MAXIMUM_PRODUCT];
	displayReportHeader();
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		reportArray[i] = calculateReportData(catFoodDetail[i]);
		if (reportArray[i].perServe < reportArray[i - 1].perServe)
		{
			cheapproduct = i;
		}
	}
	int j;
	for (j = 0; j < MAXIMUM_PRODUCT; j++)
	{
		struct ReportData x = { 0 };
		x = reportArray[j];
		displayReportData(x, cheapproduct);
		if (cheapproduct == j)
		{
			printf(" ***");
		}
		printf("\n");
	}
	displayFinalAnalysis(catFoodDetail[cheapproduct]);
}
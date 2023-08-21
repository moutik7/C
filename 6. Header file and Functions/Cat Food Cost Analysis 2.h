


#define MAXIMUM_PRODUCT 3
#define TOTAL_GRAMS 64
#define KG_IN_LBS 2.20462

struct CatFoodInfo
{
	int sku;
	double productRate;
	int calories;
	double weightInLbs;
};

struct ReportData
{
	int sku;
	double productRate;
	double weightInLbs;
	int calories;
	double kg;
	int g;
	double sumServe;
	double perServe;
	double calPerServe;
};


int getIntPositive(int* num); // Function to cheeck integer positive values

double getDoublePositive(double* Number);  // function to check floating point positive

void openingMessage(const int requiredProducts);

struct CatFoodInfo getCatFoodInfo(const int sequence_num);


void displayCatFoodHeader();

void displayCatFoodData(const int sku, const double* rate, const int caloriesPerServe, const double* weight);

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs_convert, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(const int volume, const int sum, double* result);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* rate, const double* result, double* CostofResult);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double*
	CostCalories);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo getDetailCatFood);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportinfo, const int cheap);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheaper_product);

void start();





#define MAXIMUM_PRODUCT 3
#define TOTAL_GRAMS 64

struct CatFoodInfo
{
	int sku;
	double productRate;
	int calories;
	double weightInLbs;
};

int getIntPositive(int* num); // Function to cheeck integer positive values

double getDoublePositive(double* Number);  // function to check floating point positive

void openingMessage(const int requiredProducts);

struct CatFoodInfo getCatFoodInfo(const int sequence_num);


void displayCatFoodHeader();

void displayCatFoodData(const int sku, const double* rate, const int caloriesPerServe, const double* weight);

void start();


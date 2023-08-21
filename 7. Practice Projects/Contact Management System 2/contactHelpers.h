//==============================================
// Name:           Moutikkumar Ghanshyambhai Patel
// Student Number: 147298202
// Email:          mgpatel12@myseneca.ca
// Section:        NAA
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

/*--------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks.
---------------------------------------------------------------------*/

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents here...                         |
// +-------------------------------------------------+

void clearKeyboard(void);

void pause(void);

int getInt(void);

int getIntInRange(int min, int max);

int yes(void);

int menu(void);

void contactManagerSystem(void);

void getTenDigitPhone(char phoneNum[]);

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

void displayContactHeader(void);

void displayContactFooter(int count);

void displayContact(const struct Contact* contact);

void displayContacts(const struct Contact contacts[], int size);

void searchContacts(const struct Contact contacts[], int size);

void addContact(struct Contact contacts[], int size);

void updateContact(struct Contact contacts[], int size);

void deleteContact(struct Contact contacts[], int size);

void sortContacts(struct Contact contacts[], int size);
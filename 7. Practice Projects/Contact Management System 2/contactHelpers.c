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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contacts.h"
#include "contactHelpers.h"

#define MAXCONTACTS 5

void clearKeyboard(void)
{
	while (getchar() != '\n');
}

void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	return;
}

int getInt(void)
{
	char NL;
	int Value;
	scanf("%d%c", &Value, &NL);
	while (NL != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf(" %d%c", &Value, &NL);
	}
	return Value;
}

int getIntInRange(int min, int max)
{
	int check;
	check = getInt();
	while (check < min || check > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: "
			, min, max);
		check = getInt();
	}
	return check;
}

int yes(void)
{
	char check, NL;
	int flag = -1;
	scanf("%c%c", &check, &NL);

	while (!((NL == '\n') && ((check == 'Y') || (check == 'y') ||
		(check == 'n') || (check == 'N'))))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: "
		);
		scanf("%c%c", &check, &NL);
	}
	if ((check == 'Y') || (check == 'y'))
	{
		flag = 1;
	}
	else if ((check == 'N') || (check == 'n'))
	{
		flag = 0;
	}
	return flag;
}

int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
}

void contactManagerSystem(void)
{
	int sel;
	struct Contact allContacts[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
						{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
						{ "4161112222", "4162223333", "4163334444" } },
						{
						{ "Maggie", "R.", "Greene" },
						{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
						{ "9051112222", "9052223333", "9053334444" } },
						{
						{ "Morgan", "A.", "Jones" },
						{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
						{ "7051112222", "7052223333", "7053334444" } },
						{
						{ "Sasha", {'\0'}, "Williams" },
						{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
						{ "9052223333", "9052223333", "9054445555" } },
	};
	do
	{
		sel = menu();
		switch (sel)
		{
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			int option = yes();
			if (option == 1)
			{
				printf("\nContact Management System: terminated\n");
				return;
			}
			else { printf("\n"); }

			break;
		case 1:
			displayContacts(allContacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 2:
			addContact(allContacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(allContacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(allContacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(allContacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(allContacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		default:
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> "
			);
			break;
		}

	} while ((sel >= 0) || (sel <= 6));

	return;
}

void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int i;
	while (needInput == 1)
	{

		scanf("%10[^\n]", phoneNum);
		clearKeyboard();
		if (phoneNum[10] == '\0')
		{
			needInput = 0;
		}
		for (i = 0; i < strlen(phoneNum); i++)
		{
			if ((isdigit(phoneNum[i]) == 0))
			{
				needInput = 1;
				break;
			}
		}
		if (needInput == 1)
		{
			printf("Enter a 10-digit phone number: ");
		}
	}
}

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int index = -1;
	int i;
	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			index = i;
		}
	}
	return index;
}

void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

	return;
}

void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", count);
	return;
}

void displayContact(const struct Contact* contact)
{
	char fullName[77] = { '\0' };
	if (strlen(contact->name.firstName) != 0)
	{
		strcat(fullName, contact->name.firstName);
		if (strlen(contact->name.middleInitial) != 0)
		{
			strcat(fullName, " ");
			strcat(fullName, contact->name.middleInitial);
		}
		strcat(fullName, " ");
		strcat(fullName, contact->name.lastName);
		printf(" %s\n", fullName);
		printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell,
			contact->numbers.home, contact->numbers.business);
		printf("       %d %s, ", contact->address.streetNumber,
			contact->address.street);
		if (contact->address.apartmentNumber > 0)
		{
			printf("Apt# %d, ", contact->address.apartmentNumber);
		}
		printf("%s, %s\n", contact->address.city,
			contact->address.postalCode);
	}
}

void displayContacts(const struct Contact contacts[], int size)
{
	putchar('\n');
	displayContactHeader();
	int i;
	int num = 0;
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			displayContact(&contacts[i]);
			num++;
		}
	}
	displayContactFooter(num);
	return;
}

void searchContacts(const struct Contact contacts[], int size)
{
	char numSearch[11];
	int index;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(numSearch);
	index = findContactIndex(contacts, size, numSearch);
	if (index != -1)
	{
		printf("\n");
		displayContact(&contacts[index]);
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	return;
}

void addContact(struct Contact contacts[], int size)
{
	int i;
	int index = -1;
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		putchar('\n');
		getContact(&contacts[index]);
		printf("--- New contact added! ---\n");
	}
	else
	{
		printf("\n*** ERROR: The contact list is full! ***\n");
	}
	return;
}

void updateContact(struct Contact contacts[], int size)
{
	char cell[11];
	int index;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cell);
	index = findContactIndex(contacts, size, cell);
	if (index != -1)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[index]);
		putchar('\n');
		printf("Do you want to update the name? (y or n): ");
		if (yes())
		{
			getName(&contacts[index].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes())
		{
			getAddress(&contacts[index].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes())
		{
			getNumbers(&contacts[index].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	return;
}

void deleteContact(struct Contact contacts[], int size)
{
	char cell[11];
	int index;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cell);
	index = findContactIndex(contacts, size, cell);
	if (index != -1)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[index]);
		putchar('\n');
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes())
		{
			strcpy(&contacts[index].numbers.cell[0], "\0");
			printf("--- Contact deleted! ---\n");
		}
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	return;
}


	void ContactsExchange(struct Contact* contactN, struct Contact* contactS) //here switch contact function is used for switching elements of the contact structure where address of contacts are shared here. Moreover string copy function is used here for transferring data as it is cnvinient and efficient.Moreover the main reason to use this function is that we have to exhnage the info three time per roll which would be not efficient , so making a function is efficient.
	{
		strcpy(contactN->name.firstName, contactS->name.firstName);
		strcpy(contactN->name.middleInitial, contactS->name.middleInitial);
		strcpy(contactN->name.lastName, contactS->name.lastName);
		contactN->address.streetNumber = contactS->address.streetNumber;
		strcpy(contactN->address.street, contactS->address.street);
		contactN->address.apartmentNumber = contactS->address.apartmentNumber;
		strcpy(contactN->address.city, contactS->address.city);
		strcpy(contactN->address.postalCode, contactS->address.postalCode);
		strcpy(contactN->numbers.cell, contactS->numbers.cell);
		strcpy(contactN->numbers.home, contactS->numbers.home);
		strcpy(contactN->numbers.business, contactS->numbers.business);
	}
	// sortContacts:
	void sortContacts(struct Contact contact[], int size)
	{
		int i, j, m;
		struct Contact temporaryContact;
		for (i = 0; i < size; i++)
		{
			m = i;
			for (j = i + 1; j < size; j++)
			{
				if (strcmp(contact[j].numbers.cell, contact[m].numbers.cell) < 0)
				{
					m = j;
				}
			}
			if (m != i)
			{
				ContactsExchange(&temporaryContact, &contact[i]); //here control is sent to ContactsExchnage as it is the function which changes the data of structures.
				ContactsExchange(&contact[i], &contact[m]);
				ContactsExchange(&contact[m], &temporaryContact);
			}
		}
		printf("\n--- Contacts sorted! ---\n");
	}

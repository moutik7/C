//==============================================
//Name:          Moutikkumar Ghanshyambhai Patel
// Student Number: 197298202
// Email:          mgpatel12@myseneca.ca
// Section:        NAA
// Date:   16 July 2021          
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================


// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_


struct Name
{
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

struct Address
{
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};

struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

void getName(struct Name* name);

void getAddress(struct Address* address);

void getNumbers(struct Numbers* numbers);

void getContact(struct Contact* contact);


// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Group.h"
#include "Person.h"

using namespace std;

//КОНструктор без параметров
Person::Person()
{
    cout << "Constr Person" << endl;

    FirstName = new char[40];
    strcpy(FirstName, "FN");
    LastName = new char[40];
    strcpy(LastName, "LN");
    Age = 0;
}
//КОНструктор с параметрами

Person::Person(const char* firstName, const char* lastName, unsigned age)
{
    cout << "Constr with param Person" << endl;

    FirstName = new char[strlen(firstName) + 1];
    strcpy(FirstName, firstName);
    LastName = new char[strlen(lastName) + 1];
    strcpy(LastName, lastName);
    Age = age;
}

//конструктор копирования
Person::Person(const Person& source)
{
    cout << "Copy Constr Person" << endl;

    FirstName = new char[strlen(source.FirstName) + 1];
    strcpy(FirstName, source.FirstName);
    LastName = new char[strlen(source.LastName) + 1];
    strcpy(LastName, source.LastName);
    Age = source.Age;
}

//деструктор
Person::~Person()
{
    cout << "Destr Person" << endl;

    delete[] FirstName;
    delete[] LastName;
}

void Person::Print()
{
    cout << "Fist name:" << FirstName << endl;
    cout << "Last name:" << LastName << endl;
    cout << "Age:" << Age << endl;
}

Person  Person::operator =(const Person& source)
{
    if (FirstName != NULL)
    {
        delete[] FirstName;
    }
    if (LastName != NULL)
    {
        delete[] LastName;
    }
    FirstName = new char[strlen(source.FirstName) + 1];
    strcpy(FirstName, source.FirstName);
    LastName = new char[strlen(source.LastName) + 1];
    strcpy(LastName, source.LastName);
    Age = source.Age;
    return *this;
}

void Person::Set(const char* firstName, const char* lastName, unsigned age)
{
    if (firstName != NULL && lastName != NULL && age != 0)
    {
        delete[] FirstName;
        delete[] LastName;
        FirstName = new char[strlen(firstName) + 1];
        strcpy(FirstName, firstName);
        LastName = new char[strlen(lastName) + 1];
        strcpy(LastName, lastName);
        Age = age;
    }
}

char* Person::GetFirstName()
{
    return FirstName;
}
char* Person::GetLastName()
{
    return LastName;
}

unsigned int Person::GetAge()
{
    return Age;
}

bool  Person::Save(FILE* f)
{
    if (f != NULL)
    {
      fprintf(f, "%s %s, %d. \n", FirstName, LastName, Age);
      return true;
    }
    else  return false;
}

bool Person::operator!= (const Person& source) {

    if (strcmp(FirstName, source.FirstName))
        return true;

    if (strcmp(LastName, source.LastName))
        return true;

    if (Age != source.Age)
        return true;

    return false;
}

bool Person::operator== (const Person& source) {

    if (strcmp(FirstName, source.FirstName))
        return false;

    if (strcmp(LastName, source.LastName))
        return false;

    if (Age != source.Age)
        return false;

    return true;
}
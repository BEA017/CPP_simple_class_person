#pragma once
#include <iostream>
using namespace std;

class Person
{
    char* FirstName;
    char* LastName;
    unsigned Age;

public:

    Person();
    Person(const char* firstName, const char* lastName, unsigned age);
    Person(const Person& source);
    ~Person();

    void Print();

    Person operator =(const Person& source);
    void Set(const char* firstName, const char* lastName, unsigned age);
    char* GetFirstName();
    char* GetLastName();
    unsigned int GetAge();

    bool Save(FILE* name);
    bool operator!= (const Person& source);
    bool operator== (const Person& source);





};
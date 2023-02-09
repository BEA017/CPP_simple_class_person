/*1. Разработать класс Person, имеющий следующие поля:
- char* FirstName
- char* Lastname
- unsigned Age;

- конструкторы (без параметров, копирования, с размерами)
- деструктор
- void Print() - печать группы

- сеттеры / геттеры

2. Разработать класс Group, имеющий следующие поля:
- Person** people
- MaxLength - максимальная длина группы
- CurrentLength - текущий размер группы

Методы:
- конструкторы (без параметров, копирования, с размерами)
- деструктор
- void Print() - печать группы
- Add(Person*)
 

Операторы:
- operator== - сравнение групп друг с другом
- operator= - оператор присваивания

- operator+ (Person*)
- operator+= (Person*)

Пример:

Group group(5);
group.Add(new Person(....));

group+=(new Person(....));
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Group.h"
#include "Person.h"

using namespace std;

int main()
{
    Group group(2);
    group.Add(new Person("Nik", "Nikson", 25));
    group.Add(new Person("Roman", "Pirce", 35));
    group.Add(new Person("Donald", "Duck", 45));

    group.Print();
    cout << endl;
    Group group2 = group;
    group2.Print();

  //  Group group3 = group + new Person("Billi", "Irish", 29);
 //  group3.Print();
    
   // group.SaveToFile("z:\\temp\\test.txt");
    //Group group5(2);
    //group5.LoadFromFile("z:\\temp\\test.txt");
    //cout << "  LOAD" << endl;
    //group5.Print();
    /////////////////////////////////////
    cout << "==";
    if (group == group2)                            
       cout << " YES!!" << endl;
    else
        cout << " NO!!" << endl;
    /////////////////////////////////////////
    Group group6 = group + group2;                 
    group6.Print();
    ////////////////////////////////////////
   // group += new Person("Ed", "Bill", 30);   
   // group.Print();
    ///////////////////////////////////////
   // group3 = group - new Person("Billi", "Irish", 29);
   // group3.Print();
    //////////////////////////////////////
    return 0;
}


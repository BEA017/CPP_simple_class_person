#include "Person.h"
#pragma once
#include <iostream>
using namespace std;

class Group
{
    //Динамический массив хранит указатели на персоны
    Person** People;
    size_t MaxLenght; //максимальный размер группы
    size_t CurrentLenght; // текущий размер группы

public:

    Group(size_t maxLenght); //конструктор с параметром
    Group(const Group& source);
    ~Group();// деструктор

    void Add(Person* person);// метод добавления персоны по указателю
    void Print();//метод печати
    bool SaveToFile(const char* filename);//метод сохранения 
    bool LoadFromFile(const char* fileName);//метод чтения

    Group  operator= (const Group& source);//оператор присваивания   //Group& operator= (const Group& source);//оператор присваивания с передачей по ссылке
    bool operator== (const Group& people2);//оператор сравнения

  //  Group  operator+ (Person* person);//оператор + персон
   Group  operator+ (const Group& source);//оператор + обьединения групп
    Group  operator- (Person* person);//оператор - персон с возвратом новой группы

    Group operator+= (Person* person);//прибавление по значению
    Group   operator-= (Person* person);

    Group& Remove(unsigned id);
    Group& Remove(Person* person);



};
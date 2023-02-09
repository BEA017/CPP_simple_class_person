#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Group.h"
#include "Person.h"

using namespace std;

Group::Group(size_t maxLenght) //конструктор с параемтром
{
    cout << "Constr with param Group" << endl;
    MaxLenght = maxLenght;       //максимальный размер
    CurrentLenght = 0;        //текущий размер
    People = new Person * [maxLenght];// масиив указателей

}

Group::Group(const Group& source)
{
    cout << "Copy Constr  Group" << endl;
    /*MaxLenght = source.MaxLenght;
    CurrentLenght = source.CurrentLenght;

    People = new Person* [MaxLenght];
        //перебор всех персон
    for (size_t i = 0; i < CurrentLenght; i++)
    {
        //создать копию персоны по указателю на исходную персону
        Person* person = new Person(*source.People[i]);
      
        People[i] = person; 
    }
    */

    MaxLenght = source.MaxLenght;
    CurrentLenght = 0;

    People = new Person * [MaxLenght];
    //перебор всех персон
    for (size_t i = 0; i < source.CurrentLenght; i++)
    {
        //создать копию персоны по указателю на исходную персону
        Person* person = new Person(*source.People[i]);
        //добавить персон в новую группу
        Add(person);
    }
}

Group::~Group()// деструктор 
{
    cout << "Destr  Group" << endl;

    //удаление персон из группы по адресам
    for (size_t i = 0; i < CurrentLenght; i++)
        delete People[i];
    //удаление массива указателей на машины
    delete People;
}

void Group::Add(Person* person)
{

    if (CurrentLenght < MaxLenght)
    {
        People[CurrentLenght++] = person;
    }
    else
    {
        size_t newSize = MaxLenght + 3;

        cout << "Garage resize. New size: " << newSize << endl;

        // выделить память под новый гараж
        Person**  new_people = new Person * [newSize];

        size_t i = 0;
        // перебрать все машины в исходном массиве
        for (; i < CurrentLenght; i++)
        {
            // добавить автомобиль в новый массив
            new_people[i] = People[i];
        }

        // добавить новую машину в новый массив машин
        new_people[i] = person;

        // изменить размеры с учётом новой машины
        MaxLenght = newSize;
        CurrentLenght++;

        // удалить старый массив указателей
        delete[] People;

        // сохранить новый массив с машинами в поле класса Cars
        People = new_people;
    }

}

void Group::Print()
{
    for (size_t i = 0; i < CurrentLenght; i++)
    {
        People[i]->Print();
    }


}

bool Group::SaveToFile(const char* fileName)
{
    FILE* f = fopen(fileName, "w");
    if (f != NULL)
    {
        for (int i = 0; i < CurrentLenght; i++)
        {
            if (!People[i]->Save(f))
            {
                fclose(f);
                return false;
            }
        }
        fclose(f);
        return true;
    }
    else
    {
        cout << "Error saving" << endl;
        return false;
    }

}

bool Group::LoadFromFile(const char* fileName)
{
    FILE* file_r = fopen(fileName, "r");
    if (file_r != NULL)
    {
        for (size_t i = 0; i < CurrentLenght; i++)
        {
            delete People[i];
        }
      
        CurrentLenght = 0;
        while(!feof(file_r))
        {
            unsigned int age = 0;
            char firstName[100];
            char lastName[100];
            strcpy(firstName, "");
            strcpy(lastName, "");

            fscanf(file_r, "%s %s, %d. \n", firstName, lastName, age);
            if (strlen(firstName)>0&& strlen(lastName)>0)
            {
                Person* person = new Person(firstName, lastName, age);
                Add(person);
            }
            
        }
        fclose(file_r);
        return true;
    }
    return false;
}
// перегрузка = оператора присваивание с передачей по адресу
/*Group& Group::operator= (const Group& source)
{
    if (MaxLenght!=source.MaxLenght)
    {
        for (size_t i = 0; i < CurrentLenght; i++)
        {
            delete People[i];
        }
        delete People;
       // //метод с присваиванием
     //MaxLenght = source.MaxLenght;
    //CurrentLenght = source.CurrentLenght;

   // People = new Person* [MaxLenght];
     //   //перебор всех персон
    //for (size_t i = 0; i < CurrentLenght; i++)
   // {
  //      //создать копию персоны по указателю на исходную персону
//        Person* person = new Person(*source.People[i]);

    //    People[i] = person;
   // }
    
    //метод с add
    //скоировать размеры исхщдной группы
MaxLenght = source.MaxLenght;
CurrentLenght = 0;
//выделить память под новую группу
People = new Person * [MaxLenght];
//перебор всех персон
for (size_t i = 0; i < source.CurrentLenght; i++)
{
    //создать копию персоны по указателю на исходную персону
    Person* person = new Person(*source.People[i]);
    //добавить персон в новую группу
    Add(person);
}
    }

    return *this;
}*/  //


Group Group::operator= (const Group& source)
{
    if (MaxLenght!=source.MaxLenght)
    {
        for (size_t i = 0; i < CurrentLenght; i++)
        {
            delete People[i];
        }
        delete People;
        //метод с присваиванием
        /*MaxLenght = source.MaxLenght;
    CurrentLenght = source.CurrentLenght;

    People = new Person* [MaxLenght];
        //перебор всех персон
    for (size_t i = 0; i < CurrentLenght; i++)
    {
        //создать копию персоны по указателю на исходную персону
        Person* person = new Person(*source.People[i]);

        People[i] = person;
    }
    */
        //метод с add
        //скоировать размеры исхщдной группы
        MaxLenght = source.MaxLenght;
        CurrentLenght = 0;
      //выделить память под новую группу
        People = new Person * [MaxLenght];
        //перебор всех персон
        for (size_t i = 0; i < source.CurrentLenght; i++)
        {
            //создать копию персоны по указателю на исходную персону
            Person* person = new Person(*source.People[i]);
            //добавить персон в новую группу
            Add(person);
        }
    }
 
     return *this;
}

//Group  Group::operator+ (Person* person)
//{
//    Group result = *this;
//    result.Add(person);
//    return result;
//}


Group  Group::operator- (Person* person)
{
    Group result = *this;
    result.Remove(person);
    return result;
}


bool Group::operator== (const Group& people2)
{ 
    if (CurrentLenght == people2.CurrentLenght)
    {

        for (size_t i = 0; i < CurrentLenght; i++)
        {

            if (*this->People[i] != *people2.People[i])
            {
                return false;
            }
        }
        return true;
    }
    else
        return false;
}

Group Group::operator+ (const Group& source)
{
    Group result(MaxLenght + source.MaxLenght+3);
    result.CurrentLenght = 0;
   
    for (size_t i = 0; i < CurrentLenght + source.CurrentLenght; i++)
    {
     // добавить  в новый массив
        if (i < CurrentLenght)
        {
            Person* result_person = new Person(*People[i]);
            result.Add(result_person);
        }
        else
        {
            Person* result_person = new Person(*source.People[i-CurrentLenght]);
            result.Add(result_person);
        }
    }
     return result;    
}

Group  Group::operator+= (Person* person)
{
     Add(person);
    return *this;
}

Group  Group::operator-= (Person* person)
{
    this->Remove(person);
    return *this;
}

Group& Group::Remove(unsigned id)
{
    if (id < CurrentLenght)
    {
        People[id]->~Person();
        delete People[id];
        for (size_t i = 0; i < CurrentLenght; i++)
        {
            People[i] = People[i+1];
        }
        CurrentLenght--;
        return *this;
    }
    else
        throw exception("EROR!! wrong index");
}

Group& Group::Remove(Person* person)
{
    for (size_t i = 0; i < CurrentLenght; i++)
    {
        if (People[i] == person)
        {
            People[i] = People[i + 1];
        }
    }
    CurrentLenght--;
    return *this;

}
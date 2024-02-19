#include "Animal.h"

using namespace  std;

Animal::Animal(){}

Animal::Animal(string name, int age, double weight){
    this->name1= name;
    this->age1 = age;
    this->weight1 = weight;
}

void Animal::setName(string name){
    this->name1 = name;
}

string Animal::getName(){
    return this->name1;
}

void Animal::setAge(int age){
    this->age1 = age;
}

int Animal::getAge(){
    return this->age1;
}

void Animal::changeInfo(string name, int age, double weight)
{
    this->name1=name;
    this->age1=age;
    this->weight1=weight;
}

void Animal::printInfo(){
    cout << "Name: " << this->name1 << endl;
    cout << "Age: " << this->age1 << endl;
    cout << "Weight: " << this->weight1 << endl;
}

void Animal::setWeight(double weight){
    this->weight1 = weight;
}
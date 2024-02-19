#include <iostream>
#include <string>

using namespace std;

class Animal{
public:
    Animal();
    Animal(string name, int age, double weight);

    void setName(string name);
    void setAge (int age);
    void setWeight(double weight);

    string getName();
    int getAge();
    double getWeight();

    void changeInfo(string name, int age, double weight);

    virtual void printInfo();

protected:
    string name1;
    int age1;
    double weight1;
};

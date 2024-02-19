#include "City.h"
#include "iostream"

using namespace std;

City::City(){}

City::City(string name, string latitude, string longitude){
    this->name = name;
    this->latitude = latitude;
    this->longitude = longitude;
}

#include "City.h"
#include "iostream"

using namespace std;

City::City(){}

City::City(string name, string latitude, string longitude){
    this->name = name;
    this->latitude = latitude;
    this->longitude = longitude;
}

void City::printInfo(){
    cout << "City:" << this->name << "\n";
    cout << "Latitude:" << this->latitude << "\n";
    cout << "Longitude:" << this->longitude << "\n";
}

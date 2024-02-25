#ifndef ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H
#define ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H

#include <iostream>

using namespace std;

class City{
public:
    City();
    City(string name, double latitude, double longitude);
    void printInfo(){
        cout << "City: " << this->name << "\n";
        cout << "latitude: " << this->latitude << "\n";
        cout << "longitude: " << this->longitude << "\n";
    };

protected:
    string name;
    double latitude;
    double longitude;
};


#endif //ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H

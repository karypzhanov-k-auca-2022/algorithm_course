#ifndef ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H
#define ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H

#include <iostream>

using namespace std;

class City{
public:
    City();
    City(string name, string latitude, string longitude);
    void printInfo();

protected:
    string name;
    string latitude;
    string longitude;
};


#endif //ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H

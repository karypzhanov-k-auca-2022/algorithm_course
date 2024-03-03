#ifndef ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H
#define ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H

#include <string>
#include <iostream>

class City {
private:
    std::string name;
    double latitude;
    double longitude;

public:
    City() = default;

    City(const std::string &name, double latitude, double longitude) {
        this->name = name;
        this->latitude = latitude;
        this->longitude = longitude;
    }

    std::string getName() const {
        return name;
    }

    double getLatitude() const {
        return latitude;
    }

    double getLongitude() const {
        return longitude;
    }

};

#endif //ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H

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
    City();
    City(const std::string& name, double latitude, double longitude){
        this->name = name;
        this->latitude = latitude;
        this->longitude = longitude;
    }

    void printInfo(){
        std::cout << "City: " << this->name << "\n";
        std::cout << "Latitude: " << this->latitude << "\n";
        std::cout << "Longitude: " << this->longitude << "\n";
    }

    std::string getName() const {
        return name; }
    double getLatitude() const {
        return latitude; }
    double getLongitude() const {
        return longitude; }

};

#endif //ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_CITY_H

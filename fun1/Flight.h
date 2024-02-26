#ifndef ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_FLIGHT_H
#define ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_FLIGHT_H

#include "City.h"
#include <cmath>

class Flight {

private:
    std::string origin;
    std::string destination;
    double distance;

public:

    static double calculateDistance(const City &city1, const City &city2) {
        const double R = 6371.0;  // Earth's radius in kilometers
        double lat1 = city1.getLatitude() * M_PI / 180.0;
        double lon1 = city1.getLongitude() * M_PI / 180.0;
        double lat2 = city2.getLatitude() * M_PI / 180.0;
        double lon2 = city2.getLongitude() * M_PI / 180.0;

        double dlat = lat2 - lat1;
        double dlon = lon2 - lon1;

        double a = sin(dlat / 2.0) * sin(dlat / 2.0) +
                   cos(lat1) * cos(lat2) * sin(dlon / 2.0) * sin(dlon / 2.0);
        double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

        return R * c;
    }

    Flight() = default;

    Flight(const std::string &origin, const std::string &destination, double distance) {
        this->origin = origin;
        this->destination = destination;
        this->distance = distance;
    }

    Flight(const std::string &origin, const std::string &destination) {
        this->origin = origin;
        this->destination = destination;
    }

    void printInfo() const {
        std::cout << this->origin << " and " << this->destination << " is " << this->distance
                  << " km\n";
    }

    std::string getOrigin() const {
        return origin;
    }

    std::string getDestination() const {
        return destination;
    }

    double getDistance() const {
        return distance;
    }

};

#endif //ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_FLIGHT_H

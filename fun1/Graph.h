#ifndef ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H
#define ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H

#include "iostream"
#include "vector"
#include "unordered_map"
#include "City.h"
#include "Flight.h"


class Graph {
private:
    std::unordered_map<std::string, std::vector<Flight>> adjacencyList;

public:
    Graph() = default;

    Graph(const std::vector<City> &cities, double maxDistance) {
        for (int i = 0; i < cities.size(); i++) {
            for (int j = 0; j < cities.size(); j++) {
                if (i != j) {
                    double distance = Flight::calculateDistance(cities[i], cities[j]);
                    if (distance <= maxDistance) {
                        Flight flight(cities[i].getName(), cities[j].getName(), distance);
                        adjacencyList[cities[i].getName()].push_back(flight);
                    }
                }
            }
        }
    }

    void printGraph() {
        for (const auto &city: adjacencyList) {
            std::cout << "City: " << city.first << "-> " << "\n";
            for (const auto &flight: city.second) {
                std::cout << "Destination: " << flight.getDestination() << " Distance: " << flight.getDistance()
                          << "\n";
            }
        }
    };

#endif //ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H
};
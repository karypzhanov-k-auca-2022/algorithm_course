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

    Graph(const std::vector<City> &cities, const std::vector<Flight> &flights, double maxDistance) {
        for (const auto &city: cities) {
            adjacencyList[city.getName()] = std::vector<Flight>();
        }
        for (const auto &flight: flights) {
            if (flight.getDistance() <= maxDistance) {
                adjacencyList[flight.getOrigin()].push_back(flight);
            }
        }
    }

    void printGraph() {
        for (const auto &city: adjacencyList) {
            std::cout << "City: " << city.first << "-> " << "\n";
            for (const auto &flight: city.second) {
                std::cout << flight.getDestination()<< " " << flight.getDistance()
                          << "\n";
            }
            std::cout << "\n";
        }
    };

    void addEdge(const std::string &origin, const std::string &destination, double distance) {
        Flight flight(origin, destination, distance);
        adjacencyList[origin].push_back(flight);
    }

    bool routeExists(const std::string &origin, const std::string &destination) {
        std::vector<std::string> visited;
        return routeExists(origin, destination, visited);
    }

    bool routeExists(const std::string &origin, const std::string &destination, std::vector<std::string> &visited) {
        if (origin == destination) {
            return true;
        }

        visited.push_back(origin);
        for (const auto &flight: adjacencyList[origin]) {
            if (std::find(visited.begin(), visited.end(), flight.getDestination()) == visited.end()) {
                if (routeExists(flight.getDestination(), destination, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

#endif //ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H
};
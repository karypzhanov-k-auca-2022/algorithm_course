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
                std::cout << flight.getDestination() << " " << flight.getDistance()
                          << "\n";
            }
            std::cout << "\n";
        }
    };


    std::vector<std::string> findRoute(const std::string &origin, const std::string &destination) {
        std::vector<std::string> visited; // create a vector to store visited cities
        std::vector<std::string> path = dfs(origin, destination, visited); // call the dfs function
        return path;
    }

    std::vector<std::string>
    dfs(const std::string &origin, const std::string &destination, std::vector<std::string> &visited) {
        if (origin == destination) {
            std::vector<std::string> route;
            route.push_back(origin); // add the destination to the route
            return route;
        }

        visited.push_back(origin);
        for (const auto &flight: adjacencyList[origin]) {
            if (std::find(visited.begin(), visited.end(), flight.getDestination()) ==
                visited.end()) { // if the 2nd city has not been visited yet then continue
                std::vector<std::string> path = dfs(flight.getDestination(), destination, visited); // recursive call
                if (!path.empty()) {
                    path.insert(path.begin(), origin); // insert origin to the beginning of the path
                    return path;
                }
            }
        }
        return {}; // if the route does not exist
    }

};

#endif //ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H

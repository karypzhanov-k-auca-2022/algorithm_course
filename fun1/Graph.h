#ifndef ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H
#define ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H

#include "iostream"
#include "vector"
#include "map"
#include "City.h"


class Graph {
private:
    std::vector<City> cities;
    std::map<City, std::vector<City>> adjList;
public:
    Graph(const std::vector<City>& cities) {
        this->cities = cities;
    }

    void printGraph() {
        for (const auto& city : adjList) {
            std::cout << city.first.getName() << " -> ";
            for (const auto& neighbor : city.second) {
                std::cout << neighbor.getName() << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif //ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H

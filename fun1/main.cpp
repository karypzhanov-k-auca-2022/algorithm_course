#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"

static void printLine() {
    std::cout << "----------------------------------------" << std::endl;
}

static void displayMenu1() {
    std::cout << "Please, enter the maximum positive distance between a plane can fly (km): ";
}

static void displayMenu2() {
    std::cout << "Now, tell me what do you want to accomplish?" << std::endl;
    std::cout << "1. Check if a route between two cities exists." << std::endl;
    std::cout << "2. Create a route between two cities." << std::endl;
    std::cout << "3. Create a route map between all the cities." << std::endl;
    std::cout << "4. Browse the flight network." << std::endl;
    std::cout << "5. Play a game." << std::endl;
    std::cout << "6. Exit." << std::endl;
}

int main() {
    std::ifstream file1ToRead("/Users/kai/CLionProjects/algorithms-personal-repo-karypzhanov-k-auca-2022/fun1/kg.csv");
    std::string line;
    std::vector<City> cities;
    std::vector<Flight> flights;

    //  read the file and create City objects
    while (std::getline(file1ToRead, line)) {
        std::stringstream eachLine(line);
        std::string name;
        std::string latitudeFake;
        std::string longitudeFake;

        std::getline(eachLine, name, ',');
        std::getline(eachLine, latitudeFake, ',');
        std::getline(eachLine, longitudeFake, ',');

        double latitude = std::stod(latitudeFake);
        double longitude = std::stod(longitudeFake);

        cities.emplace_back(name, latitude, longitude);    //  create City objects and add cities vector
    }

    // output code
    displayMenu1();
    double maxDistance;
    std::cin >> maxDistance;
    displayMenu2();

    int choice;
    std::cin >> choice;


    if (choice == 1) {
        std::string origin;
        std::string destination;
        std::cout << "Enter the origin city: ";
        std::cin >> origin;
        std::cout << "Enter the destination city: ";
        std::cin >> destination;

        Graph graph(cities, maxDistance);
        std::vector<std::string> route = graph.findRoute(origin, destination);

        if (!route.empty()) {
            std::cout << "The route exists." << std::endl;
        } else {
            std::cout << "The route does not exist." << std::endl;
        }
    } else if (choice == 2) {
        std::string origin;
        std::string destination;
        std::cout << "Enter the 1 city: ";
        std::cin >> origin;
        std::cout << "Enter the 2 city: ";
        std::cin >> destination;

    } else if (choice == 3) {
        Graph graph(cities, maxDistance);
        graph.printGraph();
    } else if (choice == 4) {
        std::cout << "You chose 4" << std::endl;
    } else if (choice == 5) {
        std::cout << "You chose 5" << std::endl;
    } else if (choice == 6) {
        std::cout << "bye bye!" << std::endl;
    }

    return 0;
}
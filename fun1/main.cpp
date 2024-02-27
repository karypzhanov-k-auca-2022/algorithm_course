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

    //  create Flight objects
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities.size(); j++) {
            if (i != j) {
                double distance = Flight::calculateDistance(cities[i], cities[j]);
                Flight flight(cities[i].getName(), cities[j].getName(), distance);
                flights.push_back(flight);
            }
        }
    }

//    for (const auto &flight: flights) {
//        flight.printInfo();
//    }

//  create a graph
    Graph graph(cities, 100);
    graph.printGraph();


    // output code
    /*  displayMenu1();
      double maxDistance;
      std::cin >> maxDistance;
      displayMenu2();

      int choice;
      std::cin >> choice;

      while (choice < 1 || choice > 6) {
          std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl; // validate the choice
          std::cin >> choice;
      }


      switch (choice) {
          case 1:
              std::cout << "You chose option 1" << std::endl;
              break;
          case 2:
              std::cout << "You chose option 2" << std::endl;
              break;
          case 3:
              std::cout << "You chose option 3" << std::endl;
              break;
          case 4:
              std::cout << "You chose option 4" << std::endl;
              break;
          case 5:
              std::cout << "You chose option 5" << std::endl;
              break;
          case 6:
              exit(0);
      } */

    return 0;
}
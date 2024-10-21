#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"

//  normalize the city name
std::string normalizeCityName(std::string city) {
    if (city.empty())
        return city;
    city[0] = std::toupper(city[0]);
    for (size_t i = 1; i < city.size(); ++i) {
        if (city[i - 1] == ' ') {
            city[i] = std::toupper(city[i]);
        } else {
            city[i] = std::tolower(city[i]);
        }
    }
    return city;
}

// my display function 1
static void displayMenu1() {
    std::cout << "Please, enter the maximum positive distance between a plane can fly (km): ";
}

// my display function 2
static void displayMenu2() {
    std::cout << "Now, tell me what do you want to accomplish?" << std::endl;
    std::cout << "1. Check if a route between two cities exists." << std::endl;
    std::cout << "2. Create a route between two cities." << std::endl;
    std::cout << "3. Create a route map between all the cities." << std::endl;
    std::cout << "4. Browse the flight network." << std::endl;
    std::cout << "5. Play a game." << std::endl;
    std::cout << "6. Exit." << std::endl;
}

static void displayMenu4() {
    std::cout << "Please enter the city from which you would like to start browsing." << std::endl;
}

static void displayMenu44() {
    std::cout << "Please, choose where you want to go: ";
}

// my display function 3
static void processDisplay() {
    std::cout << "Creating a route between two cities." << std::endl;
}

int main() {
    std::ifstream file1ToRead("../fun1/kg.csv");
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

        //  convert string to double
        double latitude = std::stod(latitudeFake);
        double longitude = std::stod(longitudeFake);

        cities.emplace_back(name, latitude, longitude);    //  create City objects and add cities vector
    }

    std::ifstream file2ToRead("../fun1/fly_map.csv");
    std::string line2;
    while (std::getline(file2ToRead, line2)) {
        std::stringstream eachLine(line2);
        std::string name;
        std::string latitudeFake;
        std::string longitudeFake;

        std::getline(eachLine, name, ',');
        std::getline(eachLine, latitudeFake, ',');
        std::getline(eachLine, longitudeFake, ',');

        //  convert string to double
        double latitude = std::stod(latitudeFake);
        double longitude = std::stod(longitudeFake);

        cities.emplace_back(name, latitude, longitude);    //  create City objects and add cities vector
    }

    // output code
    displayMenu1();
    double maxDistance;
    while (!(std::cin >> maxDistance) || maxDistance <= 0) { // check if the input is valid
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a positive number: ";
    }


    displayMenu2();
    int choice1;
    while (!(std::cin >> choice1) || choice1 < 1 || choice1 > 6) { // check if the input is valid
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 6: ";
    }

    // Clear input buffer
    std::cin.ignore();

    if (choice1 == 1) { // check if a route between two cities exists
        std::string origin;
        std::string destination;
        std::cout << "Enter the origin city: ";
        std::getline(std::cin, origin);
        std::string originNormalized = normalizeCityName(origin);
        std::cout << "Enter the destination city: ";
        std::getline(std::cin, destination);
        std::string destinationNormalized = normalizeCityName(destination);

        Graph graph(cities, maxDistance);
        std::vector<std::string> route = graph.findRoute(originNormalized, destinationNormalized);

        if (!route.empty()) {
            std::cout << "There is a route between " << originNormalized << " and " << destinationNormalized << "."
                      << std::endl;
        } else {
            std::cout << "There is no route between " << originNormalized << " and " << destinationNormalized << "."
                      << std::endl;
        }
    } else if (choice1 == 2) { // create a short route between two cities
        std::string origin;
        std::string destination;
        std::cout << "Enter the origin city: ";
        std::getline(std::cin, origin);
        std::string originNormalized = normalizeCityName(origin);
        std::cout << "Enter the destination city: ";
        std::getline(std::cin, destination);
        std::string destinationNormalized = normalizeCityName(destination);

        Graph graph(cities, maxDistance);
        std::vector<std::string> route = graph.shortestPath(originNormalized, destinationNormalized);
        processDisplay();

        for (auto i = route.begin(); i != route.end(); i++) {
            if (i != route.end() - 1) {
                std::cout << *i << " -> ";
            } else {
                std::cout << *i << std::endl;
            }
        }
        std::string fileName = "../fun1/shortest_path.csv";

        std::cout << "The shortest path between " << originNormalized << " and " << destinationNormalized
                  << " has been created in a file: " << fileName << "."
                  << std::endl;
        graph.shortestPathToMyMaps(route, fileName); // print the shortest path to the file

    } else if (choice1 == 3) { // create a route map between all the cities
        Graph graph(cities, maxDistance);

        auto mst = graph.kruskalMST(); // create a minimum spanning tree

        std::string fileName = "../fun1/mst.txt";
        graph.printMST(mst, fileName); // print the MST to the file

        std::cout << "The route map between all the cities has been created in a file: " << fileName << "."
                  << std::endl;

        fileName = "../fun1/MST_for_google_maps.csv";
        graph.MSTToMyMaps(mst, fileName); // print the MST to the file
        std::cout << "The MST map for google maps between all the cities has been created in a file: " << fileName
                  << "."
                  << std::endl;
    } else if (choice1 == 4) {
        Graph graph(cities, maxDistance);

        displayMenu4();
        std::string city; // user input
        std::getline(std::cin, city);
        std::string currentCity = normalizeCityName(city);

        while (true) {
            graph.moveToCity(currentCity);
            graph.displayAvailableCities();

            displayMenu44();
            int choice2;
            std::cin >> choice2;  // user input like digit
            while (!(std::cin >> choice2) || choice2 < 1 || choice2 > graph.getCurrentAvailableCities().size() + 1) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and "
                          << graph.getCurrentAvailableCities().size() + 1 << ": ";
            }
            std::cin.ignore(); // Clear input buffer

            //  check if the user input is valid
            if (choice2 >= 1 && choice2 <= graph.getCurrentAvailableCities().size()) {
                std::string selectedCity;
                selectedCity = graph.getCurrentAvailableCities()[choice2 - 1]; //  get the selected city
                currentCity = selectedCity;
            } else if (choice2 ==
                       graph.getCurrentAvailableCities().size() + 1) { // if user choose last option then exit
                std::cout << "Exiting." << std::endl;
                exit(0);
            }
        }
    } else if (choice1 == 5) {
        std::cout << "You chose 5" << std::endl;
    } else if (choice1 == 6) {
        std::cout << "bye bye!" << std::endl; // exit
        exit(0);
    } else if (choice1 == 7) {
        std::cout << "You chose 7" << std::endl;
    } else {
        std::cout << "Invalid input. Please enter a number between 1 and 6: ";
    }

    return 0;
}

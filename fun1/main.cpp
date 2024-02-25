#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "City.h"
#include "Graph.h"
#include "Flight.h"
#include "TUI.h"

using namespace std;

int main() {
    ifstream file1ToRead("/Users/kai/CLionProjects/algorithms-personal-repo-karypzhanov-k-auca-2022/fun1/kg.csv");
    string line;
    vector<City> cities;

    //  read the file and create City objects
    while (getline(file1ToRead, line)) {
        stringstream eachLine(line);
        string name;
        string latitudeFake;
        string longitudeFake;

        getline(eachLine, name, ',');
        getline(eachLine, latitudeFake, ',');
        getline(eachLine, longitudeFake, ',');

        double latitude = stod(latitudeFake);
        double longitude = stod(longitudeFake);

        cities.emplace_back(name, latitude, longitude);    //  create City objects and add cities vector
    }

    TUI tui;
    tui.displayMenu();

    return 0;
}

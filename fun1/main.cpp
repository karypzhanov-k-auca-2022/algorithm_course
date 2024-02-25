#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "City.h"
#include "Graph.h"

using namespace std;

int main() {
    ifstream file1ToRead("/Users/kai/CLionProjects/algorithms-personal-repo-karypzhanov-k-auca-2022/fun1/kg.csv");
    string line;
    vector<City> cities;

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

    for (auto& city : cities) {
        city.printInfo();
        cout << endl;
    }

//    Graph path;
//    path.addPath(0,1);
//    path.addPath(1,0);

    return 0;
}

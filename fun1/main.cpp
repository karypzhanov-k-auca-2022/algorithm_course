#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "City.h"
#include "Graph.h"

using namespace std;

int main() {
//    ifstream file("/Users/kai/CLionProjects/algorithms-personal-repo-karypzhanov-k-auca-2022/fun1/kg.csv");
//    string line;
//    vector<City> cities;
//
//    while (getline(file, line)) {
//        stringstream ss(line);
//        string name;
//        string latitude;
//        string longitude;
//
//        getline(ss, name, ',');
//        getline(ss, latitude, ',');
//        getline(ss, longitude, ',');
//
//        cities.emplace_back(name, latitude, longitude);    //  create City objects and add cities vector
//    }
//
//    for (auto& city : cities) {
//        city.printInfo();
//        cout << endl;
//    }

    Graph path;
    path.addPath(0,1);

    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "City.h"
#include "Flight.h"

using namespace std;

void displayMenu1() {
    cout << "Please, enter the maximum positive distance between a plane can fly (km): ";
}

void displayMenu2() {
    cout << "Now, tell me what do you want to accomplish?" << endl;
    cout << "1. Check if a route between two cities exists." << endl;
    cout << "2. Create a route between two cities." << endl;
    cout << "3. Create a route map between all the cities." << endl;
    cout << "4. Browse the flight network." << endl;
    cout << "5. Play a game." << endl;
    cout << "6. Exit." << endl;
}

int main() {
    ifstream file1ToRead("/Users/kai/CLionProjects/algorithms-personal-repo-karypzhanov-k-auca-2022/fun1/kg.csv");
    string line;
    vector<City> cities;

    displayMenu1();
    double maxDistance;
    cin >> maxDistance;
    displayMenu2();

    int choice;
    cin >> choice;

    while (choice < 1 || choice > 6) {
        cout << "Invalid choice. Please enter a number between 1 and 6." << endl; // validate the choice
        cin >> choice;
    }

    switch (choice) {
        case 1:
            cout << "You chose option 1" << endl;
            break;
        case 2:
            cout << "You chose option 2" << endl;
            break;
        case 3:
            cout << "You chose option 3" <<   endl;
            break;
        case 4:
            cout << "You chose option 4" <<  endl;
            break;
        case 5:
            cout << "You chose option 5" <<  endl;
            break;
        case 6:
            cout << "You chose option 6" <<  endl;
            break;
    }

    return 0;
}

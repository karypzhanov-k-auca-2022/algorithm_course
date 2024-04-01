#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void print_line() {
    cout << "-----------------------------------" << endl;
}

struct Budget {
    int financial;
    int resource;
    int ecological;
};

int main() {
    vector<string> ddata = {"data1", "data2"};
    cout << "data1 - 1" << endl;
    cout << "data2 - 2" << endl;
    int data;
    cin >> data;

    if (data < 1 || data > ddata.size()) {
        cout << "Invalid data number!" << endl;
        return 1;
    }

    string file_name_to_read = "../fun3/" + ddata[data - 1] + ".txt";

    ifstream file(file_name_to_read);
    string line;

    // data
    Budget budget;
    budget = {0, 0, 0};
    vector<int> cost;
    vector<int> capacity_increase;
    vector<int> resources_required;
    vector<int> impact_score;


    while (getline(file, line)) {
        stringstream eachLine(line);
        string word1, word2, word3;
        getline(eachLine, word1, ' ');
        getline(eachLine, word2, ' ');
        getline(eachLine, word3, ' ');

        if (word1 == "financial") {
            budget.financial = stoi(word3);
        } else if (word1 == "resource") {
            budget.resource = stoi(word3);
        } else if (word1 == "ecological") {
            budget.ecological = stoi(word3);
        }


//        string part1, part2, part3, part4;
//        getline(eachLine, part1, ',');
//        getline(eachLine, part2, ',');
//        getline(eachLine, part3, ',');
//        getline(eachLine, part4, ' ');
//
//        stringstream ss1(part1);
//        stringstream ss2(part2);
//        stringstream ss3(part3);
//        stringstream ss4(part4);


    }

    cout << "Financial budget: " << budget.financial << endl;
    cout << "Resource budget: " << budget.resource << endl;
    cout << "Ecological budget: " << budget.ecological << endl;

    return 0;
}

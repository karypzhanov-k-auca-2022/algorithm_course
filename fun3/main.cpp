#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Budget {
    int financial;
    int resource;
    int ecological;
};

struct Option {
    int cost;
    int capacity_increase;
    int resources_required;
    int impact_score;
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
    vector<Option> options;

    int n = 0;
    while (getline(file, line)) {
        stringstream eachLine(line);
        string word;
        getline(eachLine, word, ':');

        if (word == "financial") {
            getline(eachLine, word, ' ');
            budget.financial = stoi(word);
        } else if (word == "resource") {
            getline(eachLine, word, ' ');
            budget.resource = stoi(word);
        } else if (word == "ecological") {
            getline(eachLine, word, ' ');
            budget.ecological = stoi(word);
        } else if (word == "cost") {
            Option option;
            getline(eachLine, word, ',');
            option.cost = stoi(word);
            getline(eachLine, word, ':');
            getline(eachLine, word, ',');
            option.capacity_increase = stoi(word);
            getline(eachLine, word, ':');
            getline(eachLine, word, ',');
            option.resources_required = stoi(word);
            getline(eachLine, word, ':');
            getline(eachLine, word, ',');
            option.impact_score = stoi(word);
            options.push_back(option);
        }
    }

    cout << "Financial budget: " << budget.financial << endl;
    cout << "Resource budget: " << budget.resource << endl;
    cout << "Ecological budget: " << budget.ecological << endl;

    for (const auto &option: options) {
        cout << "Option: cost " << option.cost << ", capacity increase " << option.capacity_increase
             << ", resources required " << option.resources_required << ", impact score " << option.impact_score
             << endl;
    }

    return 0;
}

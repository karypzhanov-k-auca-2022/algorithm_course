#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

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

// recursive
// i - option index,
// j - financial,
// k - resource,
// l - ecological
int dp_recursive(vector<Option> &options, Budget &budget, int i, int j, int k, int l) {
    if (i == 0) {
        return 0;  // base case
    }

    if (options[i - 1].cost > j || options[i - 1].resources_required > k ||
        options[i - 1].impact_score > l) { // check if the option can be selected
        return dp_recursive(options, budget, i - 1, j, k, l); // do not update
    }

    return max(dp_recursive(options, budget, i - 1, j, k, l), // do not update
               dp_recursive(options, budget, i - 1, j - options[i - 1].cost,
                            k - options[i - 1].resources_required,
                            l - options[i - 1].impact_score)
               + options[i - 1].capacity_increase); // update
}

// Iterative
int dp_iterative(vector<Option> &options, Budget &budget, int i, int j, int k, int l) {
    vector<vector<vector<vector<int>>>> dp(options.size() + 1, vector<vector<vector<int>>>(budget.financial + 1,
                                                                                           vector<vector<int>>(
                                                                                                   budget.resource + 1,
                                                                                                   vector<int>(
                                                                                                           budget.ecological +
                                                                                                           1,
                                                                                                           0)))); // fill with 0

    for (int i = 1; i <= options.size(); i++) {
        for (int j = 1; j <= budget.financial; j++) {
            for (int k = 1; k <= budget.resource; k++) {
                for (int l = 1; l <= budget.ecological; l++) {
                    dp[i][j][k][l] = dp[i - 1][j][k][l];
                    if (options[i - 1].cost <= j && options[i - 1].resources_required <= k &&
                        options[i - 1].impact_score <= l) { // check if the option can be selected
                        dp[i][j][k][l] = max(dp[i - 1][j][k][l], // do not update
                                             dp[i - 1][j - options[i - 1].cost]
                                             [k - options[i - 1].resources_required]
                                             [l - options[i - 1].impact_score]
                                             + options[i - 1].capacity_increase); // update
                    }
                }
            }
        }
    }

    return dp.back().back().back().back();
}

void data_menu() {
    cout << "Select data (1 - 3):" << endl;
    cout << "data1 - 1" << endl;
    cout << "data2 - 2" << endl;
    cout << "data3 - 3" << endl;
}

// function to read data from txt file
bool read_from_txt(string &file_name, Budget &budget, vector<Option> &options) {
    ifstream file(file_name); // open the file
    string line;

    // read 3 lines of the file
    int n = 0;
    while (getline(file, line)) {
        stringstream eachLine(line); // read each line
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

        n++;
        if (n == 3) {
            break;
        }
    }

    // read the rest of the file
    while (getline(file, line)) {
        stringstream eachLine(line);
        string word;
        getline(eachLine, word, ':'); // read until ':'

        if (word == "cost") {
            Option option{};
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

    return true;
}

// function to read data from json file
bool read_from_json(string &file_name, Budget &budget, vector<Option> &options) {
    ifstream file(file_name); // open the file

    json data;
    file >> data;

    budget.financial = data["financial"];
    budget.resource = data["resource"];
    budget.ecological = data["ecological"];

    for (const auto &option: data["options"]) {
        options.push_back({
                                  option["cost"],
                                  option["capacity_increase"],
                                  option["resources_required"],
                                  option["impact_score"]
                          });
    }

    return true;
}

void print_line() {
    cout << "-----------------------------------------------------------------" << endl;
}

int main() {
    int choice;
    cout << "Menu (1) or see all answers from each data file (2)" << endl;
    cout << "Select 1 or 2:" << endl;
    cin >> choice;

    // error handling
    if (choice < 1 || choice > 2) {
        cerr << "Invalid choice selected" << endl;
        cerr << "Please select choice from 1 or 2" << endl;
        return 1;
    }

    vector<string> ddata = {"data1", "data2", "data3"}; // data files

    if (choice == 1) {
        Budget budget = {0, 0, 0};
        vector<Option> options;
        cout << "Select data format (1 - JSON, 2 - TXT) or to see all answers (3):" << endl;
        int number;
        cin >> number;

        // error handling
        if (number < 1 || number > 2) {
            cerr << "Invalid data format selected" << endl;
            cerr << "Please select data format from 1 or 2" << endl;
            return 1;
        }

        string file_format = (number == 1) ? "json" : "txt"; // file format


        data_menu();
        int data;
        cin >> data;

        // error handling
        if (data < 1 || data > 3) {
            cerr << "Invalid data selected" << endl;
            cerr << "Please select data from 1 to 3" << endl;
            return 1;
        }

        string file_name_to_read = "../fun3/" + ddata[data - 1] + "." + file_format; // file to read

        if (file_format == "json") {
            read_from_json(file_name_to_read, budget, options);
        }

        if (file_format == "txt") {
            read_from_txt(file_name_to_read, budget, options);
        }

        vector<vector<vector<vector<int>>>> dp(options.size() + 1, vector<vector<vector<int>>>(budget.financial + 1,
                                                                                               vector<vector<int>>(
                                                                                                       budget.resource +
                                                                                                       1,
                                                                                                       vector<int>(
                                                                                                               budget.ecological +
                                                                                                               1,
                                                                                                               0)))); // fill with 0

        int iterative_result = dp_iterative(options, budget, options.size(), budget.financial, budget.resource,
                                            budget.ecological);
        int recursive_result = dp_recursive(options, budget, options.size(), budget.financial, budget.resource,
                                            budget.ecological);

        cout << "Maximum flights served (Recursive): " << recursive_result << endl;
        cout << "Maximum flights served (Non-Recursive): " << iterative_result << endl;
    } else if (choice == 2) {
        // JSON output
        for (int i = 0; i < 3; i++) {
            Budget budget = {0, 0, 0};
            vector<Option> options;
            string file_name_to_read = "../fun3/" + ddata[i] + ".json"; // file to read
            read_from_json(file_name_to_read, budget, options);

            vector<vector<vector<vector<int>>>> dp(options.size() + 1, vector<vector<vector<int>>>(budget.financial + 1,
                                                                                                   vector<vector<int>>(
                                                                                                           budget.resource +
                                                                                                           1,
                                                                                                           vector<int>(
                                                                                                                   budget.ecological +
                                                                                                                   1,
                                                                                                                   0)))); // fill with 0


            int iterative_result = dp_iterative(options, budget, options.size(), budget.financial, budget.resource,
                                                budget.ecological);
            int recursive_result = dp_recursive(options, budget, options.size(), budget.financial, budget.resource,
                                                budget.ecological);

            cout << "Data " << "(JSON) " << i + 1 << endl;
            cout << "Maximum flights served (Recursive): " << recursive_result << endl;
            cout << "Maximum flights served (Non-Recursive): " << iterative_result << endl;

        }
        print_line();
        // TXT output
        for (int i = 0; i < 3; i++) {
            Budget budget = {0, 0, 0};
            vector<Option> options;
            string file_name_to_read = "../fun3/" + ddata[i] + ".txt"; // file to read
            read_from_txt(file_name_to_read, budget, options);

            vector<vector<vector<vector<int>>>> dp(options.size() + 1, vector<vector<vector<int>>>(budget.financial + 1,
                                                                                                   vector<vector<int>>(
                                                                                                           budget.resource +
                                                                                                           1,
                                                                                                           vector<int>(
                                                                                                                   budget.ecological +
                                                                                                                   1,
                                                                                                                   0)))); // fill with 0

            int iterative_result = dp_iterative(options, budget, options.size(), budget.financial, budget.resource,
                                                budget.ecological);
            int recursive_result = dp_recursive(options, budget, options.size(), budget.financial, budget.resource,
                                                budget.ecological);

            cout << "Data " << "(TXT) " << i + 1 << endl;
            cout << "Maximum flights served (Recursive): " << recursive_result << endl;
            cout << "Maximum flights served (Non-Recursive): " << iterative_result << endl;
        }
    }

    return 0;
}

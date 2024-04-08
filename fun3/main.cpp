#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

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
    vector<string> ddata = {"data1", "data2"}; // data files
    cout << "data1 - 1" << endl;
    cout << "data2 - 2" << endl;
    int data;
    cin >> data;

    if (data < 1 || data > ddata.size()) {
        cout << "Invalid data number!" << endl; // check if the input is valid
        return 1;
    }

    string file_name_to_read = "../fun3/" + ddata[data - 1] + ".txt"; // file to read

    ifstream file(file_name_to_read);
    string line;

    Budget budget = {0, 0, 0};
    vector<Option> options;

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

    file.clear(); // Clear the end-of-file flag
    file.seekg(0); // Reset file pointer to beginning

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

    vector<vector<vector<vector<int>>>> dp(options.size() + 1, vector<vector<vector<int>>>(budget.financial + 1,
                                                                                           vector<vector<int>>(
                                                                                                   budget.resource +
                                                                                                   1,
                                                                                                   vector<int>(
                                                                                                           budget.ecological +
                                                                                                           1,
                                                                                                           0)))); // fill with 0


    for (int i = 1; i <= options.size(); i++) {
        for (int j = 0; j <= budget.financial; j++) {
            for (int k = 0; k <= budget.resource; k++) {
                for (int l = 0; l <= budget.ecological; l++) {
                    dp[i][j][k][l] = dp[i - 1][j][k][l];
                    if (options[i - 1].cost <= j && options[i - 1].resources_required <= k &&
                        options[i - 1].impact_score <= l) {
                        dp[i][j][k][l] = max(dp[i - 1][j][k][l],
                                             dp[i - 1][j - options[i - 1].cost][k - options[i - 1].resources_required][
                                                     l - options[i - 1].impact_score] + options[i - 1].capacity_increase);
                    }
                }
            }
        }
    }

    cout << dp.back().back().back().back() << endl;

    return 0;
}

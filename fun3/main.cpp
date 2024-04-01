#include "iostream"
#include "vector"

using namespace std;

int main() {
    vector<string> ddata = {"data1", "data2"};
    cout << "data1 or data2? ";
    int data;
    cin >> data;

    string file_name_to_read = "../fun3/" + ddata[data - 1] + ".txt";

    ifstream file1ToRead(file_name_to_read);
    string line;
    vector<int> budget;
    vector<int> impact;
    vector<int> resources;
    vector<int> capacity;

    int max_budget = 1000;
    int max_impact = 100;
    int max_resources = 150;


    vector<vector<vector<vector<int>>>> dp(max_budget + 1, vector<vector<vector<int>>>(max_impact + 1,
                                                                                       vector<vector<int>>(
                                                                                               max_resources + 1,
                                                                                               vector<int>(5 + 1,
                                                                                                           -1))));
    for (int i = 0; i <= max_budget; i++) {
        for (int j = 0; j <= max_impact; j++) {
            for (int k = 0; k <= max_resources; k++) {
                for (int l = 0; l <= 5; l++) {
                    if (i == 0 || j == 0 || k == 0 || l == 0) {
                        dp[i][j][k][l] = 0;
                    }
                }
            }
        }
    }

    return 0;
}

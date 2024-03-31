#include "iostream"
#include "vector"

using namespace std;

int main() {
    vector<int> budget = {150, 200, 300, 400, 500};
    vector<int> impact = {10, 20, 30, 40, 50};
    vector<int> resources = {25, 50, 75, 100, 125};
    vector<int> capacity = {50, 60, 70, 80, 90};

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

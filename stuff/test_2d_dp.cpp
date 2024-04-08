#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> weights = {0, 1, 4, 3, 1};
    vector<int> price = {0, 1500, 3000, 2000, 2000};

    vector<vector<int>> dp(5, vector<int>(5, 0));

    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            if (weights[i] <= j) {
                dp[i][j] = max(dp[i - 1][j],          price[i] + dp[i - 1][j - weights[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[4][3] << endl;
    cout << dp.back().back() << endl;


    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int times;
    cin >> times;

    while (times--) {
        int row, col;
        cin >> row >> col;

        vector<vector<int>> matrix(row, vector<int>(col));
        vector<vector<int>> dp(row, vector<int>(col));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> matrix[i][j];
            }
        }

        dp[0][0] = matrix[0][0];

        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }

        for (int j = 1; j < col; j++) {
            dp[0][j] = dp[0][j - 1] + matrix[0][j];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
            }
        }

        cout << dp[row - 1][col - 1] << endl;
    }

    return 0;
}

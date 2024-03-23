#include "iostream"
#include <vector>

using namespace std;

vector<vector<int>> multiplication_table(int n) {
    vector<vector<int>> result(n, vector<int>(n)); // create a 2D vector of size n x n

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            result[row][col] = (row + 1) * (col + 1);
        }
    }

    return result;
}

int main() {
    int n = 3;
    vector<vector<int>> result = multiplication_table(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

long long determinant(const vector<vector<long long>> &m) {

    if (m.size() == 1) {
        return m[0][0];  //  1x1 matrix
    } else if (m.size() == 2) {
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];  // 2x2 matrix
    }

    long long result = 0;

    for (int p = 0; p < m.size(); p++) {
        long long sign;

        // plus or mines
        if (p % 2 == 0) sign = 1;
        else sign = -1;

        vector<vector<long long>> submatrix(m.begin() + 1, m.end()); // create new matrix without 1 row
        for (vector<long long> &row: submatrix) {  // take each row
            row.erase(row.begin() + p);   // erase special column
        }

        //    - or +   num from UP       each little matrix
        result += sign * m[0][p] * determinant(submatrix);
    }

    return result;
}

int main() {
    vector<vector<long long>> matrix = {{1, -2, 3},{2, 0,  3},{1, 5,  4}};

    long long det = determinant(matrix);

    cout << "Result: " << det << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int board = 9;
vector<int> targetPositions(board);
vector<int> currentPositions(board);
int moveCount;

bool isAvailable(int row, int col) {
    for (int i = 1; i < col; i++) {
        if (row == currentPositions[i] || abs(row - currentPositions[i]) == abs(col - i)) {
            return false; // If there's a conflict
        }
    }
    return true; // no conflict
}

void minSteps(int col) {
    for (int row = 1; row < board; row++) {
        if (isAvailable(row, col)) {
            currentPositions[col] = row; // place the queen at (row, col)
            if (col == 8) {
                int moves = 0;
                for (int i = 1; i < board; i++) {
                    if (targetPositions[i] != currentPositions[i]) {
                        moves++;
                    }
                }
                moveCount = min(moveCount, moves); // Update the minimum move count
            } else {
                minSteps(col + 1); // for the next column
            }
        }
    }
}


int main() {
    int caseNum = 1;
    do {
        for (int i = 1; i < board; i++) {
            int num;
            if (!(cin >> num)) {
                return 0; // exit
            }
            targetPositions[i] = num;
        }

        moveCount = 1000;
        minSteps(1); // Start from first column
        cout << "Case " << caseNum++ << ": " << moveCount << endl;
    } while (true);
}

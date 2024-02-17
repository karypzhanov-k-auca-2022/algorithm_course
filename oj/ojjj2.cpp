#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 8;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

int solveNQueens(vector<vector<int>>& board, int col) {
    if (col >= N) {
        return 0;
    }

    int min_moves = N;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            int moves = solveNQueens(board, col + 1);

            min_moves = min(min_moves, moves + (i != col)); // If i equals col, no move is needed

            board[i][col] = 0;
        }
    }

    return min_moves;
}

int main() {
    int t = 1;
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<int> queens(N);
    while (cin >> queens[0]) {
        for (int i = 1; i < N; i++) {
            cin >> queens[i];
        }

        for (int i = 0; i < N; i++) {
            board[queens[i] - 1][i] = 1;
        }

        int min_moves = solveNQueens(board, 0);

        cout << "Case " << t++ << ": " << min_moves << endl;

        board.assign(N, vector<int>(N, 0));
    }
}

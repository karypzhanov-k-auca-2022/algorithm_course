#include <iostream>
#include <vector>
#include <string>

using namespace std;

char star = '*';
bool hasQueenInRow(const vector<string> &board, int row, int col);
bool hasQueenInColumn(const vector<string> &board, int row, int col);
bool hasQueenInDiagonal(const vector<string> &board, int row, int col);
bool isValidPosition(const vector<string> &board, int row, int col);

bool isValid(const vector<string> &board) {
    int queens = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == star) {
                queens++;
                if (!isValidPosition(board, i, j)) {
                    return false;
                }
            }
        }
    }

    return queens == 8;
}

bool isValidPosition(const vector<string> &board, int row, int col) {
    return hasQueenInRow(board, row, col) && hasQueenInColumn(board, row, col) && hasQueenInDiagonal(board, row, col);
}

bool hasQueenInRow(const vector<string> &board, int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (i != col && board[row][i] == star) {
            return true;
        }
    }
    return false;
}

bool hasQueenInColumn(const vector<string> &board, int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (i != row && board[i][col] == star) {
            return true;
        }
    }
    return false;
}

bool hasQueenInDiagonal(const vector<string> &board, int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (row + i < 8 && col + i < 8 && board[row + i][col + i] == star) {
            return true;
        }
        if (row + i < 8 && col - i >= 0 && board[row + i][col - i] == star) {
            return true;
        }
        if (row - i >= 0 && col + i < 8 && board[row - i][col + i] == star) {
            return true;
        }
        if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == star) {
            return true;
        }
    }
    return false;
}


int main() {
    vector<string> board;

    int i = 0;
    while (i < 8) {
        string row;
        cin >> row;
        board.push_back(row);
        i++;
    }

    bool isCorrect = isValid(board);

    if (isCorrect) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }

    return 0;
}

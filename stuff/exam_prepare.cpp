#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool hasQueenInRow(const vector<string> &board, int row, int col);
bool hasQueenInColumn(const vector<string> &board, int row, int col);
bool hasQueenInDiagonal(const vector<string> &board, int row, int col);
bool isValidPosition(const vector<string> &board, int row, int col);

char queen = '*';

bool isValid(const vector<string> &board) {
    int queens = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == queen) { // find
                queens++;
                if (!isValidPosition(board, i, j)) {
                    return false; // immediately false
                }
            }
        }
    }

    if (queens == 8) return true;
    else return false;
}

bool isValidPosition(const vector<string> &board, int row, int col) {
    // if queen pass all cases then true
    return !(hasQueenInRow(board, row, col) || hasQueenInColumn(board, row, col) || hasQueenInDiagonal(board, row, col));
}

// check same row
bool hasQueenInRow(const vector<string> &board, int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (i != row && board[i][col] == queen) {
            // check other queen from column
            return true;
        }
    }
    return false;
}

// check same column
bool hasQueenInColumn(const vector<string> &board, int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (i != col && board[row][i] == queen) {
            // check other queen from row
            return true;
        }
    }
    return false;
}

// check same diagonal
bool hasQueenInDiagonal(const vector<string> &board, int row, int col) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i != row && j != col && abs(row - i) == abs(col - j) && board[i][j] == queen) {

                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<string> board;

    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        board.push_back(row); // each line
    }

    if (isValid(board)) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }

    return 0;
}

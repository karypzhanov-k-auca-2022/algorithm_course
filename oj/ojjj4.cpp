#include <iostream>

using namespace std;

void generateBits(int start, int finish, int size, string current) {
    if (current.size() == size) {
        if (start == finish) {
            cout << current << endl; // base case
        }
        return;
    }

    // + 0
    generateBits(start, finish, size, current + "0");
    // + 1 and increment start
    generateBits(start, finish, size, current + "1");
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int length, finish;
        cin >> length >> finish;

        generateBits(0, finish, length, "");

        if (cases > 0) {
            cout << endl; // line between cases
        }
    }
    return 0;
}

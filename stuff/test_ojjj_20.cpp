#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long n;

    while (cin >> n) {
        if (n == 0) break;

        long root = round(pow(n, 1.0 / 6.0));

        if (pow(root, 6) == n) {
            cout << "Special" << endl;
        } else {
            cout << "Ordinary" << endl;
        }
    }

    return 0;
}

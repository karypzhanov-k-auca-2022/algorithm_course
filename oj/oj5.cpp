#include <iostream>

using namespace std;

int F(int n);

int M(int n);

int F(int n) {
    if (n == 0) {
        return 1;  // base case
    }
    return n - M(F(n - 1));
}

int M(int n) {
    if (n == 0) {
        return 0;  // base case
    }
    return n - F(M(n - 1));
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "F(" << n << ") = " << F(n) << "\n";
    cout << "M(" << n << ") = " << M(n) << "\n";

    return 0;
}

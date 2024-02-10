#include <iostream>

using namespace std;

int findDigit(long n) {
    while (n > 9) { // do until stays only 1 digit
        long long sum = 0;
        while (n > 0) {
            sum += n % 10; // take last
            n /= 10; // erase last
        }
        n = sum;  // update n
    }
    return n;
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    long sum = 0;
    for (char c : n) {
        sum += c - '0';
    }
    sum *= k;

    cout << findDigit(sum) << "\n";

    return 0;
}

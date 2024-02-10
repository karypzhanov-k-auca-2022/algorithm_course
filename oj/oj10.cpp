#include <iostream>

using namespace std;

int findDigit(string n) {
    if (n.size() == 1)
        return n[0] - '0';
    int sum = 0;
    for (char c : n) {
        sum += c - '0';
    }
    return findDigit(to_string(sum));
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    string N;

    for (int i = 0; i < k; ++i) {
        N += n;
    }

    int res = 0;

    for (char i: N) {
        res += i - '0';
    }

    cout << findDigit(to_string(res)) << "\n";

    return 0;
}

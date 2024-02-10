#include <iostream>

using namespace std;

int main() {
    string n;
    int k;
    cin >> n >> k;

    string N;

    for (int i = 0; i < k; ++i) {
        N += n;
    }

    int res = 0;
    int resF = 0;

    for (char i: N) {
        res += i - '0';
    }

    N = to_string(res);

    for (char c: N) {
        resF += c - '0';
    }

    cout << resF << "\n";

    return 0;
}
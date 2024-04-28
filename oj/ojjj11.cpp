#include <iostream>
#include <string>

using namespace std;

int solution(string roman) {

    int res = 0;
    int prev = 0;
    int length = roman.length();

    for (int i = length - 1; i >= 0; i--) { // start from the end
        int cur = 0;

        switch (roman[i]) {
            case 'I':
                cur = 1;
                break;
            case 'V':
                cur = 5;
                break;
            case 'X':
                cur = 10;
                break;
            case 'L':
                cur = 50;
                break;
            case 'C':
                cur = 100;
                break;
            case 'D':
                cur = 500;
                break;
            case 'M':
                cur = 1000;
                break;
        }

        if (cur < prev) {
            res -= cur;
        } else {
            res += cur;
        }
        prev = cur;

    }
    return res;
}

int main() {
    string roman;
    cin >> roman;
    int res = solution(roman);

    cout << res << endl;
    return 0;
}

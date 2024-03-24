#include "iostream"
#include "vector"

using namespace std;

int cut_log(const std::vector<int> &p, int n) {
    if (p.size() == 0 || p.size() == 1 || n == 0) {
        return 0;
    }

    vector<int> total(n + 1, 0);

    for (int j = 0; j <= n; ++j) {
//        cout << "j: " << j << endl;
        int max_price = 0;
        for (int i = 0; i <= j; ++i) {
//            cout << max_price << " " << "(" << p[i] << "+" << total[j - i] << ")" << endl;
            max_price = max(max_price, p[i] + total[j - i]);

//            if (i == j) {
//                cout << "max price: " << max_price << endl;
//            }
        }
        total[j] = max_price;

////        for (int i = 0; i <= n; ++i) {
////            cout << p[i] << "    ";
////        }
////        cout << endl;
//
//        for (int i = 0; i <= n; ++i) {
//            cout << total[i] << "    ";
//        }
//        cout << endl;
//
//        cout << "----------------" << endl;
    }

    return total[n];
}

// indexes - length of the log
// values - price of the log
// total - max price for the log of length i
// max_price - max price for the log of length j

int main() {
    vector<int> p = {0, 1, 5, 8, 9, 10, 17, 19, 20, 24, 30};
    int n = 7;

    int result = cut_log(p, n);

    cout << "Answer: " << result << endl;

    return 0;
}
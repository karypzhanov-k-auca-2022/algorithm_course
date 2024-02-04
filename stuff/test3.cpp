#include "iostream"
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {1, 3, 5, 6, 7};

    for (int a: nums) {
        cout << a << "\n";
    }

    return 0;
}
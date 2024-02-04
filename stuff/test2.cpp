#include "iostream"
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << nums.size() << "\n";

    for (int a: nums) {
        cout << a << "\n";
    }

    cout << 1 + -1 / 2 << "\n";

    return 0;
}
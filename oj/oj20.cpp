#include <vector>
#include <iostream>

using namespace std;

int count_sheep(vector<bool> arr) {
    int count = 0;
    for (bool is_sheep: arr) {
        if (is_sheep) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<bool> arr = {true, false, true, true, false, true, false, true, true, true};
    cout << count_sheep(arr) << endl;
    return 0;
}


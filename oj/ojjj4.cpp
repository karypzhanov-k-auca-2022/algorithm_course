#include <iostream>

using namespace std;

void generateBits(int max, int times, string current, int ones) {
    if (current.size() == max) {  // Base case
        if (ones == times) {
            cout << current << endl; // Print current string
        }
        return;
    }

    // + 0  and keep the count of ones unchanged
    generateBits(max, times, current + "0", ones);
    // + 1 and increment the count of ones
    generateBits(max, times, current + "1", ones + 1);
}

int main() {
    int data;
    cin >> data;
    while (data--) {
        int N, H;
        cin >> N >> H;

        generateBits(N, H, "", 0);

        if (data > 0) {
            cout << endl; // line between datasets
        }
    }
    return 0;
}

#include "iostream"
#include <vector>

using namespace std;

int climbing_stairs(const std::vector<int> &cost) {
    int n = cost.size();

    vector<int> total_steps(n + 1, 0);

    total_steps[0] = cost[0];
    total_steps[1] = cost[1];

    for (int i = 2; i < n; ++i) {
//        cout <<"("<< total_steps[i - 1] << " " << total_steps[i - 2]  << ")" << " + " << cost[i] << endl;


        total_steps[i] = min(total_steps[i - 1], total_steps[i - 2]) + cost[i];

//
//        cout << "After step " << i << " : ";
//        for (int j = 0; j <= i; ++j)
//            cout << total_steps[j] << "    ";
//        cout << endl;
    }

    return min(total_steps[n - 1], total_steps[n - 2]);
}

int main() {
    vector<int> cost = {0, 2, 3, 2, 7, 1};
    cout << climbing_stairs(cost) << endl;
    return 0;
}
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 or n == 0) { //
            return 1;
        }

        vector<int> nums(n + 1);
        nums[0] = 1;
        nums[1] = 1;

        for (int i = 2; i <= n; ++i) {
            nums[i] = nums[i - 1] + nums[i - 2]; // add the previous two to get the current number
        }

        return nums[n]; // return the last number
    }

};


int main() {
    int n = 4;
    Solution solution;

    cout << solution.climbStairs(n) << endl;

    return 0;
}
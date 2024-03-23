#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> total(nums.size());

        total[0] = nums[0];
        total[1] = max(nums[0], nums[1]);
        // total 3 3 4 7

        // nums 3 1 1 4
        for (int i = 2; i < nums.size(); ++i) {
            total[i] = max(total[i - 1], total[i - 2] + nums[i]);
        }   // 7                4                 3 + nums4

        return total[nums.size() - 1];
    }
};

// Object Oriented Programming - стиль программирования, который использует объекты и методы
// Dymamic Programming - техника решения задачи где задача разбивается на подзадачи

int main() {
    vector<int> nums = {3, 1, 1, 4};

    Solution solution;
    cout << solution.rob(nums) << endl;

    return 0;
}
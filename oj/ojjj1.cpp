#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        permuteRecursive(nums, 0, result);
        return result;
    }

    void permuteRecursive(vector<int> &nums, int begin, vector<vector<int>> &result) {
        if (begin >= nums.size()) {
            // add the current permutation to result
            result.push_back(nums); // for [1, 2, 3]: 123, 132, 213, 231, 312, 321
            return;
        }

        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]); // swap
            permuteRecursive(nums, begin + 1, result);  //  next level
            swap(nums[begin], nums[i]); // Return to the initial state (backtrack)
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    Solution sol;
    vector<vector<int>> result = sol.permute(nums);

    // Print all generated permutations
    for (const vector<int> &permutation: result) {
        for (int num: permutation) {
            cout << num;
        }
        cout << '\n';
    }
    return 0;
}

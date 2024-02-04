#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int begin = 0;    // start
        int end = nums.size() - 1; // finish

        return createTree(begin, end, nums);
    }

    TreeNode *createTree(int begin, int end, vector<int> &nums) {
        if (begin > end) return nullptr;  // base case

        int mid = begin + (end - begin) / 2;

        TreeNode *node = new TreeNode(nums[mid]); // create new node with mid value

        node->left = createTree(begin, mid - 1, nums);
        node->right = createTree(mid + 1, end, nums);

        return node;
    }
};
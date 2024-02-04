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
        int begin = 0;
        int end = nums.size() - 1;

        return createTree(begin, end, nums);
    }

    TreeNode *createTree(int begin, int end, vector<int> &nums) {
        if (begin > end) return nullptr;

        int mid = begin + (end - begin) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        cout << "Created node with value: " << node->val << endl;

        node->left = createTree(begin, mid - 1, nums);
        node->right = createTree(mid + 1, end, nums);

        return node;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
    TreeNode* root = solution.sortedArrayToBST(nums);

    // Добавляем nullptr в массив вместо нулей
    vector<TreeNode*> treeArray;
    treeArray.push_back(root);

    for (TreeNode* node : treeArray) {
        if (node) {
            treeArray.push_back(node->left);
            treeArray.push_back(node->right);
        } else {
            treeArray.push_back(nullptr);
            treeArray.push_back(nullptr);
        }
    }

    // Выводим значения массива
    cout << "Tree Array: ";
    for (TreeNode* node : treeArray) {
        if (node)
            cout << node->val << " ";
        else
            cout << "nullptr ";
    }
    cout << endl;

    return 0;
}

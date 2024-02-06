#include "iostream"
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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> finalRes;
        dfs(root, {}, finalRes);
        return finalRes;
    }

    void dfs(TreeNode *root, string currPath, vector<string> &ans) {
        if (root == nullptr) return;  // base case

        currPath += to_string(root->val); // add to current answer

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(currPath); // add to final answer
            return;
        }

        currPath += "->";  // add if there is one more path
        dfs(root->left, currPath, ans); // check left
        dfs(root->right, currPath, ans); // check right
    }
};
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> numbers;
        func(root,numbers);
        return numbers;
    }


    void func(TreeNode* newRoot, vector<int>& newNumbers){
        if (newRoot== nullptr)
            return;

        func(newRoot->left,newNumbers);
        newNumbers.push_back(newRoot->val);
        func(newRoot->right,newNumbers);
    }
};




#include <algorithm>

using namespace std;

class TreeNode {

private:
    TreeNode *left;
    TreeNode *right;

    TreeNode()
            : left(nullptr), right(nullptr) {
    }

public:

    static bool isPerfect(TreeNode *root) {
        if (!root) return true; //  is perfect if empty

        int leftDepth = depth(root->left); //  left depth
        int rightDepth = depth(root->right); //  right depth

        // check for the same depth
        return isPerfect(root->left) && isPerfect(root->right) && (leftDepth == rightDepth);
    }

    static int depth(TreeNode *node) {
        if (!node) {
            return 0; // empty tree is 0
        }

        int leftDepth = depth(node->left); // left depth
        int rightDepth = depth(node->right); // right depth

        return 1 + max(leftDepth, rightDepth); // add +1 each time, if null then +0
    }

    static TreeNode *leaf() {
        return new TreeNode();
    }

    static TreeNode *join(TreeNode *left, TreeNode *right) {
        return (new TreeNode())->withChildren(left, right);
    }

    TreeNode *withLeft(TreeNode *left) {
        this->left = left;
        return this;
    }

    TreeNode *withRight(TreeNode *right) {
        this->right = right;
        return this;
    }

    TreeNode *withChildren(TreeNode *left, TreeNode *right) {
        this->left = left;
        this->right = right;
        return this;
    }

    TreeNode *withLeftLeaf() {
        return withLeft(leaf());
    }

    TreeNode *withRightLeaf() {
        return withRight(leaf());
    }

    TreeNode *withLeaves() {
        return withChildren(leaf(), leaf());
    }
};
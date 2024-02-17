#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool checkBST_helper(Node* root, int min, int max) {
    if (root == nullptr) return true;
    if (root->data < min || root->data > max) return false;
    return checkBST_helper(root->left, min, root->data - 1) && checkBST_helper(root->right, root->data + 1, max);
}

bool BST(Node* root) {
    return checkBST_helper(root, -1, 10001);
}


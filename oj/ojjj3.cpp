#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool checkBST_helper(Node* root, int min, int max) {
    if (root == NULL) return true; // have no child

    if (root->data < min || root->data > max) return false;

    return checkBST_helper(root->left, min, root->data - 1) && checkBST_helper(root->right, root->data + 1, max);
    //                                         new MAX                                        new MIN
}

bool checkBST(Node* root) {
    return checkBST_helper(root, -1, 10001);
}

int main() {
    Node* root = new Node();
    root->data = 5;
    root->left = new Node();
    root->left->data = 3;
    root->left->left = new Node();
    root->left->left->data = 2;
    root->left->right = new Node();
    root->left->right->data = 4;
    root->right = new Node();
    root->right->data = 7;
    root->right->left = new Node();
    root->right->left->data = 6;
    root->right->right = new Node();
    root->right->right->data = 8;

    if (checkBST(root)) {
        cout << "Binary Tree is a BST." << endl;
    } else {
        cout << "Binary Tree is not a BST." << endl;
    }

    return 0;
}

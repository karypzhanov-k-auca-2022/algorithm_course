#include "iostream"
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node *root) {
        vector<int> result;

        traverse(root, result);
        return result;
    }

    void traverse(Node *node, vector<int> &result) {
        if (node == nullptr) {
            return; // base case
        }
        result.push_back(node->val);  // add current value Final result

        for (Node *child: node->children) { // take each child
            traverse(child, result); // each child node
        }
    }
};

int main() {
    Node *node1 = new Node(1);

    Node *node2 = new Node(3);
    Node *node3 = new Node(2);
    Node *node4 = new Node(4);

    Node *node5 = new Node(5);
    Node *node6 = new Node(6);

    node1->children = {node2, node3, node4};
    node2->children = {node5, node6};

    Solution solution1;
    vector<int> result1 = solution1.preorder(node1);

    for (int val: result1) {
        cout << val << " ";
    }

    cout << endl;

    Node *node11 = new Node(1);

    Node *node22 = new Node(2);
    Node *node33 = new Node(3);
    Node *node44 = new Node(4);
    Node *node55 = new Node(5);

    Node *node66 = new Node(6);
    Node *node77 = new Node(7);
    Node *node88 = new Node(8);
    Node *node99 = new Node(9);
    Node *node1100 = new Node(10);

    Node *node1111 = new Node(11);
    Node *node1122 = new Node(12);
    Node *node1133 = new Node(13);

    Node *node1144 = new Node(14);

    node11->children = {node22, node33, node44, node55};
    node33->children = {node66, node77};
    node77->children = {node1111};
    node1111->children = {node1144};
    node44->children = {node88};
    node88->children = {node1122};
    node55->children = {node99, node1100};
    node99->children = {node1133};

    Solution solution2;
    vector<int> result2 = solution2.preorder(node11);

    for (int val: result2) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}

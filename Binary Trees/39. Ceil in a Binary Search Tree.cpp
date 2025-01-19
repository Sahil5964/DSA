#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    // Your code here
    int ans = -1;
    Node* cur = root;
    while (root) {
        if (root->data >= input) {
            ans = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    
    return ans;
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution{
public:
    int floor(Node* root, int x) {
        if (root == NULL) return -1;
        // Code here
        int ans = -1;
        Node* cur = root;
        while (cur) {
            if (cur->data <= x) {
                ans = cur->data;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return ans;
    }
};
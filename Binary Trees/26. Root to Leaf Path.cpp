#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void findPath(Node* root, vector<int> path, vector<vector<int>>& ans) {
    if (!root) return;
    path.push_back(root->data);
    
    if (!root->left && !root->right) ans.push_back(path);
    if (root->left) findPath(root->left, path, ans);
    if (root->right) findPath(root->right, path, ans);
}

vector<vector<int>> Paths(Node* root) {
    // code here
    vector<vector<int>> ans;
    findPath(root, {}, ans);
    return ans;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode* root) {
    TreeNode* cur = root;
    vector<int> right;
    if (!root) return right;

    queue<pair<TreeNode*, int>> Q;
    Q.push({root, 0});

    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();

        if (right.size() == p.second) right.push_back(p.first->val);
        else right[p.second] = p.first->val;
        
        if (p.first->left) Q.push({p.first->left, p.second + 1});
        if (p.first->right) Q.push({p.first->right, p.second + 1});
    }

    return right;
}

vector<int> leftSideView(TreeNode* root) {
    TreeNode* cur = root;
    vector<int> right;
    if (!root) return right;

    queue<pair<TreeNode*, int>> Q;
    Q.push({root, 0});

    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();

        if (right.size() == p.second) right.push_back(p.first->val);
        else right[p.second] = p.first->val;
        
        if (p.first->right) Q.push({p.first->right, p.second + 1});
        if (p.first->left) Q.push({p.first->left, p.second + 1});
    }

    return right;
}
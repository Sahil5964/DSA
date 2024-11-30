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
bool symmHelper(TreeNode* lTree, TreeNode* rTree) {
    if (!lTree && !rTree) return true;
    if ((lTree && !rTree) || (!lTree && rTree)) return false;

    return (lTree->val == rTree->val) && symmHelper(lTree->left, rTree->right) && symmHelper(lTree->right, rTree->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return symmHelper(root->left, root->right);
}
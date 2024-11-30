struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* successor(TreeNode* root) {
        TreeNode* ans = root;
        while (ans->right) 
            ans = ans->right;
        return ans;
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                successor(cur->left)->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};
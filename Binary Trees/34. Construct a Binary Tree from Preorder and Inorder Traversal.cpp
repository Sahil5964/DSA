#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int preorderIndex = 0;
    TreeNode* build(vector<int>& inorder, vector<int>& preorder, int start, int end) {
        if (start > end)
            return nullptr;
        
        int idx = preorderIndex++;
        cout << idx << " ";
        TreeNode* root = new TreeNode(preorder[idx]);

        int divide = 0;
        for (int i = start; i <= end; i++)
            if (inorder[i] == root->val) {
                divide = i;
                break;
            }

        root->right = build(inorder, preorder, divide + 1, end);
        root->left = build(inorder, preorder, start, divide - 1);

        return root;
    }
public:
    Solution(): preorderIndex(0) {}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
        TreeNode* root = build(inorder, preorder, 0, inorder.size() - 1);
        return root;
    }
};
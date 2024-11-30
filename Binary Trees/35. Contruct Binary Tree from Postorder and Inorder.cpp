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
    int postorderIndex = 0;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end) {
        if (start > end)
            return nullptr;
        
        int idx = postorder.size() - ++postorderIndex;
        cout << idx << " ";
        TreeNode* root = new TreeNode(postorder[idx]);

        int divide = 0;
        for (int i = start; i <= end; i++)
            if (inorder[i] == root->val) {
                divide = i;
                break;
            }

        root->right = build(inorder, postorder, divide + 1, end);
        root->left = build(inorder, postorder, start, divide - 1);

        return root;
    }
public:
    Solution(): postorderIndex(0) {}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = build(inorder, postorder, 0, inorder.size() - 1);
        return root;
    }
};
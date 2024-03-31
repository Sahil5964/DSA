#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int isBalancedHelp(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = isBalancedHelp(root->left);
        int right = isBalancedHelp(root->right);

        if (left == -1 || right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return (isBalancedHelp(root) == -1 ? false : true);
    }
};
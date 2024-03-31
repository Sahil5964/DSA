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
private:
    int maximum;
    int BT(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = BT(root->left);
        int right = BT(root->right);

        maximum = max(maximum, left + right);

        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        maximum = 0;
        BT(root);
        return maximum;
    }
};
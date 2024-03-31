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
    int maxSum = INT_MIN;
    int maxSumSubTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftSubTree = max(maxSumSubTree(root->left), 0);
        int rightSubTree = max(maxSumSubTree(root->right), 0);

        maxSum = max(maxSum, leftSubTree + root->val + rightSubTree);

        return max(leftSubTree + root->val, root->val + rightSubTree);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        maxSum = max(maxSum, maxSumSubTree(root));
        return maxSum;
    }
};
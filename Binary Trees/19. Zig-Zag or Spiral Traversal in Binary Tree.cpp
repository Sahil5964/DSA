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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> ans;
        bool flag = false;

        queue<TreeNode *> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int siz = Q.size();
            vector<int> level;

            for (int i = 0; i < siz; i++)
            {
                TreeNode *node = Q.front();
                Q.pop();

                level.push_back(node->val);

                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }

            if (flag)
                reverse(level.begin(), level.end());
            ans.push_back(level);

            flag = !flag;
        }

        return ans;
    }
};
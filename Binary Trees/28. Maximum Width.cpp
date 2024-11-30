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

class Solution {
private:
    int maxWidth;
    unordered_map<int, unsigned long long> firstIndexOfLevel;
    void preorder(TreeNode* root, int level, unsigned long long index) {
        if (!root) return ;

        if (firstIndexOfLevel.find(level) == firstIndexOfLevel.end()) {
            firstIndexOfLevel[level] = index;
        }

        if (maxWidth < (index - firstIndexOfLevel[level] + 1))
            maxWidth = index - firstIndexOfLevel[level] + 1;
        
        preorder(root->left, level + 1, 2LL * index);
        preorder(root->right, level + 1, 2LL * index + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        maxWidth = 0;
        firstIndexOfLevel.clear();
        preorder(root, 0, 0);
        return maxWidth;
    }
};
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    map<int, vector<int>> mp;
    queue<pair<TreeNode*, int>> Q;
    Q.push({root, 0});

    while (!Q.empty()) {
        multiset<pair<int, int>> ms;
        int n = Q.size();
        while(n--) {
            pair<TreeNode*, int> p = Q.front();
            Q.pop();

            ms.insert({p.second, p.first->val});
            if (p.first->left) Q.push({p.first->left, p.second - 1});
            if (p.first->right) Q.push({p.first->right, p.second + 1});
        }
        for (auto e : ms) mp[e.first].push_back(e.second);
    }
    for (auto e : mp) ans.push_back(e.second);

    return ans;
}
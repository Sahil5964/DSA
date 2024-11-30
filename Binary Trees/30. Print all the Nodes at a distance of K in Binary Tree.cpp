#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    void storeParent(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        parentMap[node] = parent;
        storeParent(node->left, node);
        storeParent(node->right, node);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        storeParent(root, nullptr);

        int level = 0;
        vector<int> ans;
        unordered_map<TreeNode*, bool> visit;

        queue<TreeNode*> Q;
        Q.push(target);
        visit[target] = true;

        while (!Q.empty()) {
            int Qsize = Q.size();
            
            if (level++ == k) {
                while (!Q.empty()) { ans.push_back(Q.front()->val); Q.pop(); }
                return ans;
            }
            
            while (Qsize--) {
                TreeNode* node = Q.front();
                Q.pop();

                if (parentMap[node] && !visit[parentMap[node]]) Q.push(parentMap[node]);
                if (node->left && !visit[node->left]) Q.push(node->left);
                if (node->right && !visit[node->right]) Q.push(node->right);

                visit[parentMap[node]] = true;
                visit[node->left] = true;
                visit[node->right] = true;
            }
        }

        return ans;
    }
};
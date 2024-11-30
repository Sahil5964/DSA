#include <string>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialTree = "";
        if (!root) return serialTree;

        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();

            if (node == nullptr) serialTree.append("#,");
            else serialTree.append(to_string(node->val) + ",");

            if (node) {
                Q.push(node->left);
                Q.push(node->right);
            }
        }

        return serialTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        if (data == "") return root;

        stringstream stream(data);
        string str;
        getline(stream, str, ',');
        root = new TreeNode(stoi(str));

        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();

            getline(stream, str, ',');
            node->left = (str == "#") ? nullptr : new TreeNode(stoi(str));
            getline(stream, str, ',');
            node->right = (str == "#") ? nullptr : new TreeNode(stoi(str));

            if (node->left) Q.push(node->left);
            if (node->right) Q.push(node->right);
        }

        return root;
    }
};

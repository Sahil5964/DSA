#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<vector<int>> levelorder(Node *root)
{
    if (!root)
        return {};

    vector<vector<int>> traversal;
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        vector<int> level;
        int n = Q.size();

        for (int i = 0; i < n; i++)
        {
            Node *node = Q.front();
            Q.pop();

            level.push_back(node->data);

            if (node->left)
                Q.push(node->left);
            if (node->right)
                Q.push(node->right);
        }

        traversal.push_back(level);
    }

    return traversal;
}
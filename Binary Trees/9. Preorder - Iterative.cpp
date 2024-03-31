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

vector<int> preorder(Node *root)
{
    if (!root)
        return {};

    vector<int> preOrder;
    stack<Node *> stck;

    stck.push(root);

    while (!stck.empty())
    {
        Node *node = stck.top();
        stck.pop();

        preOrder.push_back(node->data);

        if (node->right)
            stck.push(node->right);
        if (node->left)
            stck.push(node->left);
    }

    return preOrder;
}
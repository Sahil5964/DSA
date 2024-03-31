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

vector<int> inorder(Node *root)
{
    if (!root)
        return {};

    vector<int> inOrder;
    stack<Node *> stck;
    Node *node = root;

    while (true)
    {
        if (node)
        {
            stck.push(node);
            node = node->left;
        }
        else
        {
            if (stck.empty())
                break;
            node = stck.top();
            stck.pop();

            inOrder.push_back(node->data);
            node = node->right;
        }
    }

    return inOrder;
}
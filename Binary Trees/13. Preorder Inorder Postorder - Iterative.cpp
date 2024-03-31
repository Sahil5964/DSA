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

vector<int> traversal(Node *root)
{
    if (!root)
        return {};

    stack<pair<Node *, int>> stck;
    stck.push({root, 1});

    vector<int> preOrder, inOrder, postOrder;

    while (!stck.empty())
    {
        Node *node = stck.top().first;
        int num = stck.top().second;
        stck.pop();

        if (num == 1)
        {
            preOrder.push_back(node->data);
            stck.push({node, 2});

            if (node->left)
                stck.push({node->left, 1});
        }

        if (num == 2)
        {
            inOrder.push_back(node->data);
            stck.push({node, 3});

            if (node->left)
                stck.push({node->left, 1});
        }

        if (num == 3)
        {
            postOrder.push_back(node->data);
        }
    }

    return postOrder;
}
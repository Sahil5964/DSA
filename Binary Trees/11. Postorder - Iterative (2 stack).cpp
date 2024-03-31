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

vector<int> postorder(Node *root)
{
    if (!root)
        return {};

    stack<Node *> stck1, stck2;

    stck1.push(root);
    while (!stck1.empty())
    {
        Node *node = stck1.top();
        stck1.pop();

        stck2.push(node);
        if (node->left)
            stck1.push(node->left);
        if (node->right)
            stck1.push(node->right);
    }

    vector<int> postOrder;

    while (!stck2.empty())
    {
        postOrder.push_back(stck2.top()->data);
        stck2.pop();
    }

    return postOrder;
}
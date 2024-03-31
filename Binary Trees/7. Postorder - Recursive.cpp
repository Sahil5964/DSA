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

void postorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}
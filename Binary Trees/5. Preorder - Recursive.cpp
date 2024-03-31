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

void preorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
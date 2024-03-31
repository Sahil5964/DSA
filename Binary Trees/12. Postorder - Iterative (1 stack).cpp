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

    Node *cur = root;
    Node *temp;
    stack<Node *> stck;
    vector<int> postOrder;

    while (cur || !stck.empty())
    {
        if (cur)
        {
            stck.push(cur);
            cur = cur->left;
        }
        else
        {
            temp = stck.top()->right;

            if (!temp)
            {
                temp = stck.top();
                stck.pop();
                postOrder.push_back(temp->data);

                while (!stck.empty() && temp == stck.top()->right)
                {
                    temp = stck.top();
                    stck.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
            {
                cur = temp;
            }
        }
    }

    return postOrder;
}
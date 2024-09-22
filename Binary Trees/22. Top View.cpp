#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

vector<int> topView(Node *root)
{
    //Your code here
    vector<int> ans;
    map<int, int> mp;
    
    queue<pair<Node*, int>> Q;
    Q.push({root, 0});
    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        
        if (mp.find(p.second) == mp.end())
            mp[p.second] = p.first->data;
        
        if (p.first->left) Q.push({p.first->left, p.second - 1});
        if (p.first->right) Q.push({p.first->right, p.second + 1});
    }
    
    for (auto it : mp) ans.push_back(it.second);
    
    return ans;
}
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    void populateParentChildRelationship(Node* root, unordered_map<Node*, Node*>& pMap) {
        if (!root) return ;
        
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            Node* node = Q.front();
            Q.pop();
            
            if (node->left) {
                pMap[node->left] = node;
                Q.push(node->left);
            }
            
            if (node->right) {
                pMap[node->right] = node;
                Q.push(node->right);
            }
        }
    }
    
    Node* findTargetNode(Node* root, int target) {
        if (!root) return NULL;
        if (root->data == target) return root;
        
        Node* left = findTargetNode(root->left, target);
        Node* right = findTargetNode(root->right, target);
        
        if (left && left->data == target) return left;
        return right;
    }
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> parentMap;
        unordered_map<Node*, bool> visit;
        populateParentChildRelationship(root, parentMap);
        Node* targetNode = findTargetNode(root, target);

        queue<pair<Node*, int>> Q;
        Q.push({targetNode, 0});
        visit[targetNode] = true;
        
        int maxTime = 0;
        while (!Q.empty()) {
            Node* node = Q.front().first;
            int time = Q.front().second;
            Q.pop();
            
            maxTime = max(maxTime, time);
            
            if (parentMap.find(node) != parentMap.end() && 
                visit.find(parentMap[node]) == visit.end()) {
                visit[parentMap[node]] = true;
                Q.push({parentMap[node], time + 1});
            }
            
            if (node->left && visit.find(node->left) == visit.end()) {
                visit[node->left] = true;
                Q.push({node->left, time + 1});
            }
            
            if (node->right && visit.find(node->right) == visit.end()) {
                visit[node->right] = true;
                Q.push({node->right, time + 1});
            }
        }
        
        return maxTime;
    }
};
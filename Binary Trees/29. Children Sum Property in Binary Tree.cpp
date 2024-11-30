struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution{
    int sumProperty(Node* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->data;
        
        int left = sumProperty(root->left);
        int right = sumProperty(root->right);
        
        if (left == -1 || right == -1) return -1;
        return (root->data == left + right ? root->data : -1); 
    }
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        if (!root) return 1;
        return sumProperty(root) == -1 ? 0 : 1;
    }
};
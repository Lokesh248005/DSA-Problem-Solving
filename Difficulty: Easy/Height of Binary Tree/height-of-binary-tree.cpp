/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int helper(Node* root) {
        // code here
        if(root==NULL) return 0;
        
        int lh =helper(root->left);
        int rh =helper(root->right);
        
        return 1+max(lh,rh);
    }
    int height(Node* root){
        int a =helper(root);
        return a-1;
    }
    
};

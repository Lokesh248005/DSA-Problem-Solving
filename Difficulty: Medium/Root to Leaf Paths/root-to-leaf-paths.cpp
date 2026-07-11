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
  
    void helper(vector<vector<int>>&ans,vector<int>&ds,Node* root){
        if(root==NULL){
            return;
        }
        
        ds.push_back(root->data);
        if(root->left==NULL&&root->right==NULL) ans.push_back(ds);
        else{helper(ans,ds,root->left);
        helper(ans,ds,root->right);}
        ds.pop_back();
        
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(ans,ds,root);
        return ans;
    }
};
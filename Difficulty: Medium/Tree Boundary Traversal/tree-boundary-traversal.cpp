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
    bool isLeaf(Node* node){
        if(node->left==NULL&&node->right==NULL) return true;
        return false;
    }
    void leftinsert(Node* root,vector<int>&ans){
        Node* cur =root->left;
        while(cur){
            if(!(isLeaf(cur))) ans.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else{
                cur=cur->right;
            }
        }
    }
    void leafinsert(Node* root,vector<int>&ans){
        if(root==NULL) return;
        if((isLeaf(root))) ans.push_back(root->data);
        if(root->left) leafinsert(root->left,ans);
        if(root->right) leafinsert(root->right,ans);
        
    }
    void rightinsert(Node* root,vector<int> &ans){
        Node* cur =root->right;
        vector<int>temp;
        while(cur){
            if(!(isLeaf(cur))) temp.push_back(cur->data);
            if(cur->right) cur =cur->right;
            else{
                cur =cur->left;
            }
        }
        int size =temp.size()-1;
        for(int i= size;i>=0;i--){
            ans.push_back(temp[i]);
        }
        
    }
    vector<int> boundaryTraversal(Node *root) {
          vector<int>ans;
          if(!root) return ans;
          if(!isLeaf(root)) ans.push_back(root->data);
          leftinsert(root,ans);
          leafinsert(root,ans);
          rightinsert(root,ans);
        
    return ans;
        
    }
};
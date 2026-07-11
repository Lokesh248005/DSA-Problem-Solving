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
    vector<int> rightView(Node *root) {
        vector<int>ans;
        queue<Node*>q;
        if(root==NULL) return ans;
        q.push(root);
        while(!(q.empty())){
            int size =q.size();
            for(int i=0;i<size;i++){
                Node*temp =q.front();
                q.pop();
                if(temp->right!=NULL) q.push(temp->right);
                if(temp->left!=NULL) q.push(temp->left);
                if(i==0) ans.push_back(temp->data);
                
            }
        }
        
    }
};
/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int>ans;
        queue<Node*>q;
        bool flag =true;
        int index;
        if(root==NULL) return ans;
        q.push(root);
         while(!q.empty()){
             int size =q.size();
             vector<int>level(size);
             for(int i=0;i<size;i++){
                Node* temp =q.front();
                q.pop();
            
                if(flag){
                    index=i;
                }
                else{
                    index =size-i-1;
                }
                level[index] =temp->data;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                
                    
                }
            flag= !flag;
            for(int x:level){
                ans.push_back(x);
            }
            
        }
         
        return ans;
    }
        
};
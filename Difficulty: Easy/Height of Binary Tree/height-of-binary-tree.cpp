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
    int height(Node* root) {
    int count=0;
    if(root==NULL) return count;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        count++;
        int size =q.size();
        for(int i=0;i<size;i++){
            Node* temp =q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);

        }
    }
    return count-1;
        
    }
};
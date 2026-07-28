/*
class Node {
  public:
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
    int minTime(Node* root, int target) {
        int time=0;
        if(root==NULL) return time;
        Node* ref =NULL;
        queue<Node*>q;
        map<Node*,Node*>parent;
        parent[root]=NULL;
        q.push(root);
        int ele=0;
        while(!q.empty()){
            int size=q.size();
            ele+=size;
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->data==target){
                ref=temp; 
                }
                if(temp->left){
                    q.push(temp->left);
                    parent[temp->left]=temp;
                }
                if(temp->right){
                    q.push(temp->right);
                    parent[temp->right]=temp;
                }
            }
    }
        if(ref==NULL) return time;
        map<Node*,bool>visited;
        q.push(ref);
        visited[ref]=true;
        while(!(q.empty())&&(visited.size()!=ele)){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node*temp=q.front();
                q.pop();
                if(temp->left&&!visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right&&!visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                Node*par=parent[temp];
                if(par!=NULL&&!visited[par]){
                    q.push(par);
                    visited[par]=true;
                }
            }
            time=time+1;
            
        }
        return time;
        
    }
};
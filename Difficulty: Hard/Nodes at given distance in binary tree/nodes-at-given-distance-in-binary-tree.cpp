/* Structure of Binary Tree Node
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
    vector<int> kDistanceNodes(Node* root, int target, int k) {
        vector<int>ans;
        queue<Node*>q;
        Node* rel=NULL;
        map<Node*,Node*>parent;
        if(root==NULL) return ans;
        parent[root]=NULL;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* temp =q.front();
                if(temp->data==target){
                    rel=temp;
                }
                q.pop();
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
        if(rel==NULL) return ans;
        map<Node*,bool>visited;
        q.push(rel);
        visited[rel]=true;
        while(!(q.empty())&&k>0){
            int size=q.size();
            for(int i =0;i<size;i++){
            Node* temp =q.front();
            q.pop();
            if(temp->left&&!visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right&&!visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
            }
            Node* par = parent[temp];
            if(par!=NULL&&!visited[par]){
                q.push(par);
                visited[par]=true;
            }
            }
        k--;
        }
    while(!(q.empty())){
        ans.push_back(q.front()->data);
        q.pop();
        
    }
    sort(ans.begin(),ans.end());
    return ans;
    }
};
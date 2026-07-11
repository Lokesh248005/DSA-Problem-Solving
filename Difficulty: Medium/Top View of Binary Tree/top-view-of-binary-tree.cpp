/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<pair<Node*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!(q.empty())){
            auto p = q.front();
            Node* temp =p.first;
            int x =p.second;
            q.pop();
            if(mpp.find(x)==mpp.end()){
            mpp[x]=temp->data;}
            if(temp->left!=NULL) q.push({temp->left,x-1});
            if(temp->right!=NULL) q.push({temp->right,x+1});
        }
        for(auto a:mpp){
            ans.push_back(a.second);
        }
    return ans;    
    }
};
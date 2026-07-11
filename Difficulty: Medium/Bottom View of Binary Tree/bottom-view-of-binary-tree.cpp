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
    vector<int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<pair<Node*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!(q.empty())){
            auto p =q.front();
            q.pop();
            Node* temp =p.first;
            int x = p.second;
            if(mpp.find(x)==mpp.end()){
                mpp[x] =temp->data;
            }
            else{
                mpp[x] =temp->data;
            }
            
            if(temp->left!=NULL) q.push({temp->left,x-1});
            if(temp->right!=NULL) q.push({temp->right,x+1});
        }
        for(auto a:mpp){
            ans.push_back(a.second);
        }
    return ans; 
    }
};
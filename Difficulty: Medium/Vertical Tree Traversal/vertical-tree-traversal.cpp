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
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        queue<pair<Node*,pair<int,int>>>q;
        map<int,map<int,vector<int>>> nodes;
        if(root==NULL) return ans;
        q.push({root,{0,0}});
        while(!(q.empty())){
            auto a =q.front();
            q.pop();
            Node* temp =a.first;
            int x =a.second.first; int y =a.second.second;
            nodes[x][y].push_back(temp->data);
            if(temp->left!=NULL) q.push({temp->left,{x-1,y+1}});
            if(temp->right!=NULL) q.push({temp->right,{x+1,y+1}});
        }
        for(auto p : nodes){
            vector<int>col;
            for(auto i:p.second){
                col.insert(col.end(),i.second.begin(),i.second.end());
            }
    
            ans.push_back(col);               
}   
     
return ans;        
}
};
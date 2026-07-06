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
    vector<int> inOrder(Node* root) {
        Node*node =root;
        stack<Node*>st;
        vector<int>ans;
        while(true){
            if(node!=NULL){
                st.push(node);
                node =node->left;
            }
            else{
                if(st.empty()==true) break;
                node =st.top();
                st.pop();
                ans.push_back(node->data);
                node =node->right;
            }
            
        }
        return ans;
    }
};
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int>tra;
        stack<Node*>st;
        if(root==NULL) return {} ;
        
        st.push(root);
        while(!(st.empty())){
            Node* temp =st.top();
            st.pop();
            if(temp->right!=NULL)st.push(temp->right);
            if(temp->left!=NULL) st.push(temp->left);
            tra.push_back(temp->data);
        }
    
    return tra;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(vector<int> &tra,TreeNode*root){
        if(root==NULL){
            return;
        }
        helper(tra,root->left);
        helper(tra,root->right);
        tra.push_back(root->val);
    } 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>tra;
        helper(tra,root);
        return tra;
    }
};
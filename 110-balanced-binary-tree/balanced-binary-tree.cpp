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
    int helper(TreeNode* root){
        if(root==NULL) return 0;

        int lh =helper(root->left);
        int rh =helper(root->right);
        if(lh==-1||rh==-1) return -1;
        else if(abs(lh-rh)>1) return -1;

        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        int count = helper(root);
        if(count ==-1) return false;
        return true;
    }
};
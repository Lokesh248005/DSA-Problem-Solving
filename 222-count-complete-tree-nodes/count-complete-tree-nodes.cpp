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
    int findleft(TreeNode* root){
        TreeNode*temp = root;
        int lh=0;
        while(temp){
            lh++;
            temp =temp->left;
        }
        return lh;
    }
    int findright(TreeNode* root){
        TreeNode*temp =root;
        int rh=0;
        while(temp){
            rh++;
            temp=temp->right;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;    
        int lh =findleft(root);
        int rh =findright(root);
        if(lh==rh) return((1<<lh)-1);
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
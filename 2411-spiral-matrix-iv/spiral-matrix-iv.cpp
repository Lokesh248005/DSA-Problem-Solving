/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n));
        int top=0;int left =0;int bottom =m-1;int right =n-1;
        ListNode* temp = head;
        while(top<=bottom&&left<=right){
            for(int i=left;i<=right;i++){
            if(temp!=NULL){
            matrix[top][i]=temp->val;
            temp =temp->next;
            }
            else{
            matrix[top][i]=-1;
            }
            }
            top++;
            for(int i=top;i<=bottom;i++){
            if(temp!=NULL){
            matrix[i][right]=temp->val;
            temp =temp->next;
            }
            else{
            matrix[i][right]=-1;
            }
            }
            right--;
            if(top<=bottom){
            for(int i=right;i>=left;i--){
            if(temp!=NULL){
            matrix[bottom][i]=temp->val;
            temp =temp->next;
            }
            else{
            matrix[bottom][i]=-1;
            }
            }
            bottom--;
            }
            if(left<=right){
            for(int i=bottom;i>=top;i--){
            if(temp!=NULL){
            matrix[i][left]=temp->val;
            temp =temp->next;
            }
            else{
            matrix[i][left]=-1;
            }
            }
            left++;
        }
        }
    return matrix;
    }
};
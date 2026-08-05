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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy =new ListNode(-1);
        ListNode* temp =dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            ListNode* tr = lists[i];
            if(tr!=NULL){
                pq.push({tr->val,tr});
            }
        }
        while(!(pq.empty())){
        auto o = pq.top();
        pq.pop();
        ListNode* pre = o.second;
        temp->next=pre;
        temp=temp->next;
        if(pre->next!=NULL){
            pq.push({pre->next->val,pre->next});
        } 
    }
    return dummy->next;
    }
};
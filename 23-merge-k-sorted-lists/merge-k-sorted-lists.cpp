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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        priority_queue<ListNode*,vector<ListNode*>,decltype([](ListNode* a,ListNode* b){
              return a->val>b->val;
        })>pq;
        for(int i=0;i<list.size();i++){
            if(list[i]){
                pq.push(list[i]);
            }
        }
        ListNode* ans=new ListNode(0);
        ListNode* temp2=ans;
        while(!pq.empty()){
            ListNode* temp=pq.top();
            pq.pop();
            ans->next=temp;
            ans=ans->next;
            if(temp->next){
                pq.push(temp->next);
            }
        }
        return temp2->next;
    }
};
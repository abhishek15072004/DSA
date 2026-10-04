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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int a=0,b=0;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        temp=head;
        int ct=0;
     while(temp){
        ct++;
        if(ct==k){
            a=temp->val;
        }
        if(ct==n-k+1){
            b=temp->val;
        }
        temp=temp->next;
     }

     temp=head;
     ct=0;
        while(temp){
            ct++;
            if(ct==k){
        temp->val=b;
            }else if(ct==n-k+1){
               temp->val=a;
            }
                temp=temp->next;
            }
        
        return head;

    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ct=0;
        
        ListNode* temp=head;
        while(temp){
            ct++;
            temp=temp->next;
        }
        if(n==ct)return head->next;
        ct=ct-n;
        temp=head;
        int nct=0;
        ListNode* prev=NULL;
        while(temp){
            if(nct==ct){
                prev->next=temp->next;
            }
            nct++;
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};
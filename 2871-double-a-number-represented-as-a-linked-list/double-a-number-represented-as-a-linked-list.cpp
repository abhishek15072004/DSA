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
ListNode* reverselist(ListNode* head){
    ListNode* temp=head;
    ListNode* prev=NULL;
    ListNode* forward=head;
    while(temp){
    forward=forward->next;
    temp->next=prev;
    prev=temp;
    temp=forward;
    }
    return prev;
}
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=reverselist(head);
        ListNode* temp2=new ListNode(0);
        ListNode* temp3=temp2;
        int carry=0;
        while(temp){ 
        int x=(temp->val)*2+carry;
        ListNode* temp4=new ListNode(x%10);
        temp3->next=temp4;
        temp3=temp3->next;
        carry=x/10;
        temp=temp->next;
        }
        if(temp==NULL && carry!=0){
            temp3->next=new ListNode(carry);
            temp3=temp3->next;
        }
        return reverselist(temp2->next);
       
    }
};
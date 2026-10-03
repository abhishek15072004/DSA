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
ListNode* reverselist(ListNode* l1){
    ListNode* prev=NULL;
    ListNode* temp=l1;
    ListNode* forward=l1;
    while(temp){
        forward=forward->next;
        temp->next=prev;
        prev=temp;
        temp=forward;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=reverselist(l1);
        ListNode* head2=reverselist(l2);
        ListNode* temp1=new ListNode(0);
        ListNode* temp2=temp1;
        int carry=0;
        while(head1 || head2 || carry!=0){
            int x=0,y=0;
            if(head1){
            x=head1->val;
            head1=head1->next;
            }
            if(head2){
                y=head2->val;
                head2=head2->next;
            }
            int sum=x+y+carry;
            ListNode* temp3=new ListNode(sum%10);
            carry=sum/10;
            temp2->next=temp3;
            temp2=temp2->next;
        }
       return reverselist(temp1->next);
    }
};
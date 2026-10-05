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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp && temp->next){
            ListNode* first=temp;
            ListNode* second=temp->next;
            first->next=second->next;
            second->next=first;
          
            if(prev){
                prev->next=second;
            }else{ 
               head=second;
        }
         prev=first;
         temp=first->next;
        }
        return head;
    }
};
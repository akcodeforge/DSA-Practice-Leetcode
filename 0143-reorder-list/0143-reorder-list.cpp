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
ListNode* reverse(ListNode* head){
    if(head==NULL || head->next == NULL) return head;
    ListNode* newhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;

}
    void reorderList(ListNode* head) {
    //    if(head && head->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        }
        ListNode* second=reverse(slow->next); 
        ListNode* first=head;
        slow->next=NULL; 
        // merging first and second list
        ListNode* c=new ListNode(100);
        ListNode* tempc=c;
        ListNode* tempa=first;
        ListNode* tempb=second;
        while(tempa && tempb){
            tempc->next=tempa;
            tempa=tempa->next;
            tempc=tempc->next;
            tempc->next=tempb;
            tempb=tempb->next;
            tempc=tempc->next;
        }
        tempc->next=tempa;
        head=c->next;
    }
};
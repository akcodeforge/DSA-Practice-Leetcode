class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head; 
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *NEXT=NULL;

        while(curr){
            NEXT=curr->next;
            curr->next=prev;
            prev=curr;
            curr=NEXT;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
            ListNode* node= reverseList(slow->next);
            slow->next=node;
        ListNode *x=head;
        ListNode *y=node;
        while(y){
            if(x->val!=y->val) return false;
            else{
                x=x->next;
                y=y->next;
            }
        }
        return true;
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* temp = head;
        while(temp != NULL ){
            bool flag=false;
            while(temp->next != NULL && temp->val == temp->next->val){
                flag = true;
                temp = temp->next;
            }
            if (flag) {
                prev->next = temp->next;
            } else {
                prev = prev->next;
            }

            temp = temp->next;
        }
        return dummy->next;
        
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->val == temp->next->val){
                temp->next = temp->next->next;
            }
            else temp= temp->next;
        }
        return head;
        // ListNode* a = head;
        // ListNode* b = head->next;
        // while (b != NULL) {
        //     while (b != NULL && a->val == b->val) {
        //         b = b->next;
        //     }
        //     a->next = b;
        //     a = b;
        //     if(b != NULL) b = b->next;
        // }
        // return head;
    }
};
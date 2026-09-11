class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL)
            return NULL;
        ListNode* one = head;
        ListNode* two = head->next;
        while (two->next != NULL && two->next->next != NULL) {
            one = one->next;
            two = two->next->next;
        }
        one->next = one->next->next;
        return head;
    }
};
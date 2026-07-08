class Solution {
public:
    ListNode* mergetwolist(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        if (!list1 && !list2)
            return NULL;
        while (list1 != NULL && list2!= NULL) {
            if (list1->val <= list2->val) {
                ans->next = list1;
                list1 = list1->next;
            } else {
                ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }
        if (list1 == NULL)
            ans->next = list2;
        else
            ans->next = list1;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is middle left element
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = NULL;
        a = sortList(a);
        b = sortList(b);
        ListNode* c = mergetwolist(a, b);
        return c;
    }
};
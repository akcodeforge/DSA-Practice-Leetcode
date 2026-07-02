class Solution {
public:
    ListNode* reverse(ListNode* head, int n) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (n--) {
            ListNode* NEXT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NEXT;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = &dummy;
        for (int i = 1; i < left; i++) {
            temp = temp->next;
        }
        ListNode* left1 = temp;
        ListNode* left2 = temp->next;
        ListNode* curr = temp;
        for (int i = 1; i <= right - left + 1; i++) {
            curr = curr->next;
        }
        ListNode* right2 = curr->next;
        ListNode* right1 = reverse(left2, right - left + 1);

        left1->next = right1;
        left2->next = right2;
        return dummy.next;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap = 1;
        while (temp && temp->next) {
            int remLen = 0;
            ListNode* t = temp->next;
            for (int i = 1; i <= gap + 1 && t != NULL; i++) {
                t = t->next;
                remLen++;
            }
            if (remLen < gap + 1)
                gap = remLen - 1;
            if (gap % 2 != 0)
                reverseBetween(temp, 2, 2 + gap);
            gap++;
            for (int i = 1; temp != NULL && i <= gap; i++) {
                temp = temp->next;
            }
        }
        return head;
    }
};
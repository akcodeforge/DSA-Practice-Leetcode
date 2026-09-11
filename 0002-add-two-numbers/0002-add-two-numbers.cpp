class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int c=0;
        while (l1!=NULL || l2!=NULL || c!=0) {
            int sum=c;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            int x=sum%10;
            c =sum/10;
            ListNode* temp = new ListNode(x);
            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }

        }
        return head;
    }
};
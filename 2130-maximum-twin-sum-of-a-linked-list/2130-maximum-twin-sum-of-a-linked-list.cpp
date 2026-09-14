class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        vector<int>ans;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        int result=0;
        int i=0;
        int j=n-1;
        while(i<j){
            int x=ans[i]+ans[j];
            result=max(result,x);
            i++;
            j--;
        }
        return result;
    }
};
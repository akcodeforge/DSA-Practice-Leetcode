class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
     vector<int>ans;
     int idx=1;
     int fidx=-1;
     int sidx=-1;
     ListNode* prev=head;   
     ListNode* curr=head->next; 
     while(curr->next!=NULL){
        int a=prev->val;
        int b=curr->val;
        int c=curr->next->val;
        if((b<a && b<c)|| (b>a && b>c)){
            if(fidx==-1) fidx=idx;
            else sidx=idx;
        }
            prev=prev->next;
            curr=curr->next;
            idx++;
     } 
     if(sidx==-1){
        return {-1, -1};
     }
     int mindis=INT_MAX;
     int maxdis=sidx-fidx;
     fidx=-1;
     sidx=-1;
     prev=head;   
     curr=head->next;
     while(curr->next!=NULL){
        int a=prev->val;
        int b=curr->val;
        int c=curr->next->val;
        if((b<a && b<c)|| (b>a && b>c)){
            fidx=sidx;
            sidx=idx;
            mindis=min(mindis,sidx-fidx);
        }
            prev=prev->next;
            curr=curr->next;
            idx++;
     }
     return {mindis,maxdis}; 
    }
};
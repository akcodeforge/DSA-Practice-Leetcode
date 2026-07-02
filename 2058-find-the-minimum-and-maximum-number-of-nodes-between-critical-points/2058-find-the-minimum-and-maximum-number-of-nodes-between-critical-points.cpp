class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
     int idx=1;
     int fidx=-1;
     int sidx=-1;
     int mindis=INT_MAX;
     int f=-1;
     int s=-1;   
     ListNode* prev=head;   
     ListNode* curr=head->next; 
     while(curr->next!=NULL){
        int a=prev->val;
        int b=curr->val;
        int c=curr->next->val;
        if((b<a && b<c)|| (b>a && b>c)){
            ///maxdistance
            if(fidx==-1) fidx=idx;
            else sidx=idx;
            //mindistance
            f=s;
            s=idx;
            if(f!=-1) mindis=min(mindis,s-f);

        }
            prev=prev->next;
            curr=curr->next;
            idx++;
     } 
     if(sidx==-1){
        return {-1, -1};
     }
     int maxdis=sidx-fidx;
     return {mindis,maxdis}; 
    }
};
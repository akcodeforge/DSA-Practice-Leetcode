class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=capacity.size();
        for(int i=0;i<n;i++){
            int x=capacity[i]-rocks[i];
            
            pq.push(x);
        }
        int ans=0;
        while(pq.size()>0){
            int top=pq.top();
            // if(top==0){
            //     ans +=1;
            //     pq.pop();
            // }
            if(top<=additionalRocks){
                ans += 1;
                additionalRocks -=top;
                pq.pop();
            }
            else{
                break;
            }
        }
        return ans;
    }
};
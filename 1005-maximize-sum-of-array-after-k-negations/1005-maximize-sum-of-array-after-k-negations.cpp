class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>p;
        for(int x:nums){
            p.push(x);
        }
        while(k>0 && p.top()<0){
            int s=p.top();
            p.pop();
            p.push(-s);
            k--;
        }
        if(p.top()==0) k=0;
        if(k!=0){
            while(k--){
               int a=p.top();
               p.pop();
               p.push(-a); 
            }
        }
        int sum=0;
        while(p.size()>0){
            sum +=p.top();
            p.pop();
        }
        return sum;
    }
};
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long>>p;
        priority_queue<long long>q;
        for(int i=0;i<n;i++){
            long long x=nums[i]*nums[i];
            p.push(x);
            q.push(x);
        }
        long long ans=0;
        int i=0;
        while(i<n){
            if(i%2==0){
                ans +=(q.top());
                q.pop();
            }
            else{
                ans -=(p.top());
                p.pop();
            }
            i++;
        }
        return ans;
    }
};
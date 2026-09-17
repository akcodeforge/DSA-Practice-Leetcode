class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>dp(n+1,1e9);
        int ans=1e9;
        int add=0;
        int z=0;
        for(int i=0;i<n;i++){
            add +=arr[i];
            while(add>target){
                add -=arr[z];
                z++;
            }
            dp[i+1]=dp[i];
            if(add==target){
                int x=i-z+1;
                if(dp[z]!=1e9){
                    ans=min(ans,x+dp[z]);
                }
                dp[i+1]=min(dp[i+1],x);
            }
        }
        return (ans==1e9)?-1 :ans;
    }
};
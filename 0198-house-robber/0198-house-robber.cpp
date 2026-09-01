class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp,int sum){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2){
            return max(nums[nums.size()-2],nums[nums.size()-1]);
        }
        if(dp[i]!=-1) return dp[i];
        // sum +=nums[i];
        return dp[i]=max(nums[i]+solve(nums,i+2,dp,sum),0+solve(nums,i+1,dp,sum));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int sum=0;
        return solve(nums,0,dp,sum);
    }
};
class Solution {
public:
    bool solve(vector<int>& nums,int i,vector<int>&dp){
        if(i==nums.size()-1) return true;
        if(i>=nums.size()) return false;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(solve(nums,i+j,dp)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};
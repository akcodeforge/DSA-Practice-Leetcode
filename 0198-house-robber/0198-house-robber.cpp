class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i == nums.size() - 1)
            return nums[i];
        if (i == nums.size() - 2) {
            return max(nums[nums.size() - 2], nums[nums.size() - 1]);
        }
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = max(nums[i] + solve(nums, i + 2, dp),
                           0 + solve(nums, i + 1, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, dp);
    }
};
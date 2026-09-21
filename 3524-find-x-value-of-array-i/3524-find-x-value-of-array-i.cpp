class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int i = 0; i < n; i++) {
            vector<long long> temp(k, 0);
            temp[nums[i] % k]++;
            for (int j = 0; j < k; j++) {
                if (dp[j] > 0) {
                    int z = (j * (nums[i] % k)) % k;
                    temp[z] += dp[j];
                }
            }
            for (int j = 0; j < k; j++) {
                ans[j] += temp[j];
            }

            dp = temp;
        }
        return ans;
    }
};
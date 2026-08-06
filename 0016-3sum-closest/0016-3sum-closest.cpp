class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int ans = 0;
        int rem = INT_MAX;
        int result = 0;
        for (int i = 0; i < n - 2; i++) {
            int x = i + 1;
            int j = n - 1;
            while (x < j) {
                ans = nums[i] + nums[x] + nums[j];
                if (ans < target)
                    x++;
                else if (ans > target)
                    j--;
                else
                    return ans;
                if (abs(ans - target) < rem) {
                    rem = abs(ans - target);
                    result = ans;
                }
            }
        }
        return result;
    }
};
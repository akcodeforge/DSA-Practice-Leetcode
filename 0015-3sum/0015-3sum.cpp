class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for (int z = 0; z < n; z++) {
            if (z > 0 && nums[z] == nums[z - 1])
                continue;
            int i = z + 1;
            int j = n - 1;
            int x = -nums[z];
            while (i < j) {
                int sum = nums[i] + nums[j];
                if (sum == x) {
                    v.push_back({nums[z], nums[i], nums[j]});
                    i++;
                    j--;
                    while (i < j && nums[i] == nums[i - 1])
                        i++;
                    while (i < j && nums[j] == nums[j + 1])
                        j--;
                } else if (sum < x)
                    i++;
                else
                    j--;
            }
        }
        return v;
    }
};
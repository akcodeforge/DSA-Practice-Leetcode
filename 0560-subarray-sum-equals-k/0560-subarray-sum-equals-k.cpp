class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp;
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans.push_back(sum);
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == k){
                count++;
            }
                int rem = ans[i]-k;
                if (mp.find(rem) != mp.end()) {
                    count +=mp[rem];
                }
                    mp[ans[i]]++;
        }
        return count;
    }
};
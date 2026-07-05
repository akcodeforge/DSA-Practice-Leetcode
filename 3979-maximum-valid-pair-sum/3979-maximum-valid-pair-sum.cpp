class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int a=0;
        for(int i=k;i<n;i++){
            a=max(a,nums[i-k]);
            ans=max(ans,a+nums[i]);
        }
        return ans;
    }
};
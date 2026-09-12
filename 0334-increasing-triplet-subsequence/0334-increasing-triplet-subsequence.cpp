class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int s=INT_MAX;
        int ss=INT_MAX;
        for(int i=0;i<n;i++){
            if(s>=nums[i]) s=nums[i];
            else if(ss>=nums[i]) ss=nums[i];
            else return true;
        }
        return false;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid+1]<nums[mid]) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};
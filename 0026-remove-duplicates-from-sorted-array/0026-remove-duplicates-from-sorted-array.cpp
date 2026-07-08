class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        while(j<n){
            if(nums[i]==nums[j]) j++;
            else {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
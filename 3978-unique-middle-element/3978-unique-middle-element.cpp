class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        int a=nums[n/2];
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==a){
                count++;
            }
        }
        if(count>1) return false;
        return true;
    }
};
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {

        int n = nums.size();
        int midIdx = -1;
        for(int i =1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                midIdx = i;
                break;
            }
        }
        if(midIdx == -1) return -1;
        long a=0;
        long b = 0;
        for(int i = 0;i<=midIdx ;i++){
            a +=nums[i];
        }
        for(int i = midIdx;i<n ;i++){
            b +=nums[i];
        }
        if(a>b) return 0;
        if(b>a) return 1;
        return -1;
    }
};
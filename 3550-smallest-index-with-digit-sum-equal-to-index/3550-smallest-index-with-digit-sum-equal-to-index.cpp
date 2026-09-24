class Solution {
public:
    int sum(int i){
        int ans=0;
        int x=i;
        while(x>0){
            int z=x%10;
            ans +=z;
            x /=10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==sum(nums[i])) return i;
        }
        return -1;
    }
};
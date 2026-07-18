class Solution {
public:
    #define MOD 1000000007
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size();
        long long ans=0;
        long long x=0;
        long long y=0;
        for(auto ele:nums){
            if(ele<a) ans +=x+y;
            else if(ele<=b){
                ans +=y;
                x++;
            }
            else y++;
            ans%MOD;
        }
        return ans%MOD;
    }
};
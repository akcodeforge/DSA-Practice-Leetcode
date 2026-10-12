#define MOD 1000000007
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> arr(32,0);
        for(int &num:nums){
            for(int i=0;i<32;i++){
                if(num & (1<<i)) arr[i]++;
            }
        }
        long long ans=0;
        while(k>0){
            long long z=0;
            for(int i=0;i<32;i++){
                if(arr[i]>0){
                    arr[i]--;
                    z= (z | (1<<i));
                }
            }
            ans =(ans + (z *z)%MOD)%MOD;
            k--;
        }
        return ans;
    }
};
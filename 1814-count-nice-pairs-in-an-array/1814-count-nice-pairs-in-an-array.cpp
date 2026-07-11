class Solution {
public:
int rev(int n){
    int ans=0;
    while(n>0){
        ans *=10;
        ans +=n%10;
        n /=10;
    }
    return ans;
}
    int countNicePairs(vector<int>& nums) {
       int n=nums.size();
       const int MOD=1000000007;
       long long count=0;
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
            int x=nums[i]-rev(nums[i]);
            if(mp.find(x)!=mp.end()){
                count =(count +mp[x])%MOD;
            }
                mp[x]++;
       }
       return count;
    }
};
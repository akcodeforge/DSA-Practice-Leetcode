class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) nums[i]=-1;
        }
        unordered_map<int,int>mp;
        int sum=0;
        int maxi=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum +=nums[i];
            if(mp.find(sum)!=mp.end()){
                int x=i-mp[sum];
                maxi=max(maxi,x);
            }
            else{
                mp[sum]=i;
            }
        }
        return maxi;
    }
};
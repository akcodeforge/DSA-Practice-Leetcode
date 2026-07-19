class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        for(auto ele:nums){
            int rem=k-ele;
            if(mp[rem]>0){
                count++;
                mp[rem]--;
            }
            else{
                mp[ele]++;
            }
        }
        return count;
    }
};
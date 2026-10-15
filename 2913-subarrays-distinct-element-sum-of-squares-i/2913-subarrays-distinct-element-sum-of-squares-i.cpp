class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            st.insert(nums[i]);
            ans ++;
            int c=1;
            for(int j=i+1;j<n;j++){
                if(st.count(nums[j])){
                    ans +=(c*c);
                    continue;
                }
                else{
                    c++;
                    ans +=(c*c);
                    st.insert(nums[j]);
                }
            }
        }
        return ans;
    }
};
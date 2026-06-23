class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int> st;
        // st.push(nums[n-1]);
        // ans[n-1]=nums[n-1];
        for(int i=0;i<2*n;i++){
            while(st.size()>0 && nums[st.top()]<nums[i%n]){
                ans[st.top()]=nums[i%n];
                st.pop();
            }
            if(i<n)
            st.push(i);
        }
        return ans;
    }
};
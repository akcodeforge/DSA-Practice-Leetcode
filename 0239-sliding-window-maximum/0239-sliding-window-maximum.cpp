class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int ngi[n];
        stack<int>st;
        st.push(n-1);
        ngi[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.size()==0) ngi[i]=n;
            else ngi[i]=st.top();
            st.push(i);
        }
        vector<int>ans;
        int j=0;
        for(int i=0;i<=n-k;i++){
            if(j<i) j=i;
            int mx=nums[j];
            while(j<i+k){
                mx=nums[j];
                if(ngi[j]>=i+k) break;
                j=ngi[j];
            }
            ans.push_back(mx);  
        }
        return ans;
    }
};
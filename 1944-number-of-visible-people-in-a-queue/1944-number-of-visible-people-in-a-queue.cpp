class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> nge(n,0);
        stack<int>st;
        st.push(heights[n-1]);
        nge[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int count=0;
            while(st.size()>0 && st.top()<=heights[i]){
                st.pop();
                count++;
            }
            if(st.size()>0) count++;
            nge[i]=count;
            st.push(heights[i]);
        }
        return nge;
    }
};
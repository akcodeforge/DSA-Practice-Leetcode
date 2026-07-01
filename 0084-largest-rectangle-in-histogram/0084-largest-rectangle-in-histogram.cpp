class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int nse[n];
        stack<int> st;
        nse[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            /// pop all the element smaller than arr[i]
            while (st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.size() == 0)
                nse[i] = n;
            else
                nse[i] = st.top();

            //// push back
            st.push(i);
        }
        int pse[n];

        /// pop,ans,push method and forward traverse
        //// sc=0(n)   and tc=0(n)

        stack<int> pt;
        pse[0] = -1;
        pt.push(0);
        for (int i = 1; i < n; i++) {
            /// pop all the element smaller than arr[i]
            while (pt.size() > 0 && heights[pt.top()] >= heights[i]) {
                pt.pop();
            }
            if (pt.size() == 0)
                pse[i] = -1;
            else
                pse[i] = pt.top();

            //// push back
            pt.push(i);
        }
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mx = max(mx, (heights[i] * (nse[i] - pse[i] - 1)));
        }
        return mx;
    }
};
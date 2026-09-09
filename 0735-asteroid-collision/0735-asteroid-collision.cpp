class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int x : asteroids) {
            if (x > 0) {
                st.push(x);
            } else{
                bool flag = true;
                while (flag && !st.empty() && st.top() > 0) {
                    int a = st.top();
                    int b = abs(x);
                    if (a < b)
                        st.pop();
                    else if (a == b) {
                        st.pop();
                        flag = false;
                    } else
                        flag = false;
                }
                if(flag) st.push(x);
            }
        }
        int n = st.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
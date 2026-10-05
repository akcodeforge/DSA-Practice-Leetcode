class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        stack<int>st;
        st.push(0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(0);
            else{
                int x=st.top();
                st.pop();
                int val;
                if(x==0) val =1;
                else val =(2*x);
                st.top() +=val;
            }
        }
        return st.top();
    }
};
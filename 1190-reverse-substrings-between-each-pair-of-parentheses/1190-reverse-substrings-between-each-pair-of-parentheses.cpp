class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                string temp="";
                while(st.top()!='('){
                    temp +=st.top();
                    st.pop();
                }
                st.pop();
                for(int i=0;i<temp.length();i++){
                    st.push(temp[i]);
                }
            }
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans =st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
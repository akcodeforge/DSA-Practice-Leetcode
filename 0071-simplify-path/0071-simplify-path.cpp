class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int n=path.length();
        int i=0;
        while(i<n){
            if(path[i]=='/'){
                i++;
                continue;
            }
            string temp="";
            while(i<n && path[i]!='/'){
                temp +=path[i];
                i++;
            }
            if(temp=="."){
                i++;
                continue;
            }
            if(temp==".."){
                if(!st.empty()) st.pop();
                continue;
            }
            st.push(temp);
        }
        stack<string>rt;
        while(st.size()>0){
            rt.push(st.top());
            st.pop();
        }
        string ans="";
        ans +='/';
        while(rt.size()>0){
            ans +=rt.top();
            ans +='/';
            rt.pop();
        }
        if(ans[ans.size()-1]=='/') ans.pop_back();
        if(ans.size()==0) ans +='/';
        return ans;
    }
};
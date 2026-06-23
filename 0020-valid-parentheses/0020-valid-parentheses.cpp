class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;
        stack<char>ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                if(ans.size()==0) return false;
                else{
                    if(ans.top()=='(') ans.pop();
                    else return false;
                }
            }
            else if(s[i]=='}'){
                if(ans.size()==0) return false;
                else{
                    if(ans.top()=='{') ans.pop();
                    else return false;
                }
            }
            else if(s[i]==']'){
                if(ans.size()==0) return false;
                else{
                    if(ans.top()=='[') ans.pop();
                    else return false;
                }
            }
            else ans.push(s[i]);
        }
        if(ans.size()==0) return true;
        else return false;
    }
};
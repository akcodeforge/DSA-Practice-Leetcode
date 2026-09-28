class Solution {
public:
    int maxDepth(string s) {
        int cl=0;
        int cr=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') cl++;
            else if(s[i]==')') cr++;
            ans =max(ans,(cl-cr));
        }
        return (ans!=0)?ans:(cl-cr);
    }
};
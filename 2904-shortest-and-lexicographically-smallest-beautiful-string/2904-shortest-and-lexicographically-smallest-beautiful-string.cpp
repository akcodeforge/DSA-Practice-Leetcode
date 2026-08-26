class Solution {
public:
    string check(string ans,string x){
        int n=ans.length();
        for(int i=0;i<n;i++){
            if(ans[i]!=x[i]){
                if(ans[i]=='0') return ans;
                else return x;
            }
        }
        return ans;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            int count=0;
            if(s[i]=='1') count=1;
            string x="";
            x +=s[i];
            if(count==k) return x;
            for(int j=i+1;j<n;j++){
                if(s[j]=='1') count++;
                x +=s[j];
                if(count==k) break;
            }
            if (count != k) continue;
            if(ans.size()==0) ans = x;
            else if(ans.size()==x.size()) {
                ans = check(ans,x);
            }
            else if(ans.size()>x.size()){
                ans = x;
            }
            else continue;
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int result=0;
        vector<int>ans(3,0); /// for a,b,c counting
        int i=0;
        int j=0;
        while(j<n){
            char ch=s[j];
            ans[ch-'a']++;
            while(ans[0]>0 && ans[1]>0 && ans[2]>0){
                result +=(n-j);
                ans[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return result;
    }
};
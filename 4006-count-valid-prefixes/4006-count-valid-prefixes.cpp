class Solution {
public:
    int countValidPrefixes(string s) {
        int ans=0;
        int count1 = 0;
        int count0 =0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') count0++;
            else if (s[i]=='1') count1++;
            if(abs(count0-count1)<=1) ans++;
        }
        return ans;
    }
};
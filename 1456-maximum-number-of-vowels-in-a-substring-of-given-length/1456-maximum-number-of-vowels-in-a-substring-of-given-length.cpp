class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') ans++;
        }
        int len=ans;
        for(int i=1;i+k<=n;i++){
            if(s[i+k-1]=='a' || s[i+k-1]=='e' || s[i+k-1]=='i' || s[i+k-1]=='o' || s[i+k-1]=='u'){
                len++;
            }
            if(s[i-1]=='a' || s[i-1]=='e' || s[i-1]=='i' || s[i-1]=='o' || s[i-1]=='u'){
                len--;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};
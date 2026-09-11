class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int ans=0;
        int n=s.length();
        int len=0;
        int i=0;
        for(int j=0;j<n;j++){
            while(st.find(s[j])!=st.end()) {
                st.erase(s[i]);
                i++;
                len--;
            }
            st.insert(s[j]);
            len ++;

            ans =max(ans,len);
        }
        return ans;
    }
};
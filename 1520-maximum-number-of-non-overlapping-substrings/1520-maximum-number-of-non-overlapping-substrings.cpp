class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        
        int n = s.size();

        vector<int> a(26, -1); 
        vector<int> b(26, -1);

        vector<bool> isValid(26, true);

        for(int i = 0; i < n; i++) {
            if(a[s[i]-'a'] == -1) {
                a[s[i]-'a'] = i; 
            }
            b[s[i]-'a'] = i;
        }

        for(int i = 0; i < 26; i++) {
            if(a[i] == -1) continue;

            for(int c = a[i]; c <= b[i]; c++) {
                if(a[s[c]-'a'] < a[i]) {
                    isValid[i] = false;
                    break;
                }

                b[i] = max(b[i], b[s[c]-'a']);
            }
        }

        vector<string> ans;
        int z = 1e9;
        for(int i = n-1; i >= 0; i--) {
            if(!isValid[s[i]-'a']) continue;

            if(a[s[i]-'a'] == i && b[s[i]-'a'] < z) {
                ans.push_back(s.substr(i, b[s[i]-'a']-i+1));
                z = i;
            }
        }

        return ans;

    }
};
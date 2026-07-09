class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        unordered_set<string> ans;
        for (int i = 0; i < n; i++) {
            ans.insert(words[i]);
        }
        for (int i = 0; i < n; i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if (words[i] != rev) {
                if (ans.find(rev) != ans.end()) {
                    count++;
                    ans.erase(words[i]);
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    bool IsP(string& s, int i, int j, vector<vector<int>>& z) {
        if (i >= j) return true;
        if (z[i][j] != -1) return z[i][j];

        return z[i][j] = (s[i] == s[j] && IsP(s, i + 1, j - 1, z));
    }
    int solve(string& s, int i, int k, vector<int>& dp,vector<vector<int>>& z) {
        int n = s.size();
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = solve(s, i + 1, k, dp,z);
        for (int j = i + k - 1; j < n; j++) {
            if (IsP(s, i, j, z))
                ans = max(ans, 1 + solve(s, j + 1, k, dp, z));
        }

        return dp[i] = ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(s.size(), -1);
        vector<vector<int>> z(n, vector<int>(n, -1));
        return solve(s, 0, k, dp,z);
    }
};
class Solution {
public:
    int solve(string& text1, string& text2, int i, int j,
              vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();
        if (i == n || j == m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solve(text1, text2, i + 1, j + 1, dp);
        } else {
            ans = max(ans, (solve(text1, text2, i + 1, j, dp)));
            ans = max(ans, (solve(text1, text2, i, j + 1, dp)));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int x = max(text1.size(), text2.size());
        vector<vector<int>> dp(x, vector<int>(x, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
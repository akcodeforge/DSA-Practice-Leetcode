class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[2001];
    vector<int> v;

    int solve(int n) {
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        int ttl = (2LL * solve(n - 1)) % MOD;
        if (v[n] != 0) {
            int duplicates = solve(v[n] - 1);
            ttl = (ttl - duplicates + MOD) % MOD;
        }
        return dp[n] = ttl;
    }
    int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        v.assign(n + 1, 0);
        vector<int> prev(26, 0);
        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';
            v[i] = prev[idx];
            prev[idx] = i;
        }
        return (solve(n) - 1 + MOD) % MOD;
    }
};
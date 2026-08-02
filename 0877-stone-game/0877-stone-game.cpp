class Solution {
public:
    int t[501][501];
    int solve(int i, int j, vector<int>& piles) {
        if (i > j)
            return 0;
        if (i == j)
            return piles[i];
        if (t[i][j] != -1) {
            return t[i][j];
        }
        int takei = piles[i] - solve(i + 1, j, piles);
        int takej = piles[j] - solve(i, j - 1, piles);
        return t[i][j] = max(takei, takej);
    }
    bool stoneGame(vector<int>& piles) {
        memset(t, -1, sizeof(t));
        int n = piles.size();
        return (solve(0, n - 1, piles) >= 0);
    }
};
class Solution {
public:
    int t[23][23];
    int solve(int i, int j, vector<int>& nums) {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];
        if (t[i][j] != -1) {
            return t[i][j];
        }
        int takei = nums[i] - solve(i + 1, j, nums);
        int takej = nums[j] - solve(i, j - 1, nums);
        return t[i][j] = max(takei, takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        return (solve(0, n - 1, nums) >= 0);
    }
};
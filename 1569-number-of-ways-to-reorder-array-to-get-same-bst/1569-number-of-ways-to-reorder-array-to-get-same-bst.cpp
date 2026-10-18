class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> x, y;

    long long power(long long a, long long b) {
        long long z = 1;
        while (b) {
            if (b & 1) z = z * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return z;
    }

    long long nCr(int n, int r) {
        return x[n] * y[r] % MOD
             * y[n - r] % MOD;
    }

    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ans = nCr(n - 1, left.size());
        ans = ans * solve(left) % MOD;
        ans = ans * solve(right) % MOD;

        return ans;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        x.resize(n + 1);
        y.resize(n + 1);

        x[0] = 1;
        for (int i = 1; i <= n; i++)
            x[i] = x[i - 1] * i % MOD;

        y[n] = power(x[n], MOD - 2);

        for (int i = n - 1; i >= 0; i--)
            y[i] = y[i + 1] * (i + 1) % MOD;

        return (solve(nums) - 1 + MOD) % MOD;
    }
};
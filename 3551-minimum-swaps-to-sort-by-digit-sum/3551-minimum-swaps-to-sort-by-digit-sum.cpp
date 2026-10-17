
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++) {
            int s = 0, x = nums[i];

            while (x > 0) {
                s += x % 10;
                x /= 10;
            }

            v[i] = {s, nums[i]};
        }

        vector<pair<pair<int, int>, int>> x(n);

        for (int i = 0; i < n; i++) {
            x[i] = {v[i], i};
        }

        sort(x.begin(), x.end());

        vector<bool> z(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (z[i] || x[i].second == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!z[j]) {
                z[j] = true;
                j = x[j].second;
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }
};
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr;
        vector<int> pmax(n + 1, INT_MIN);
        vector<int> smin(n + 1, INT_MAX);
        vector<int> d(n, 0);

        for (int i = 0; i < n; i++) {
            pmax[i + 1] = max(pmax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            smin[i] = min(smin[i + 1], nums[i]);
        }

        for (int i = 1; i < n; i++) {
            d[i] = d[i - 1] + (nums[i - 1] > nums[i]);
        }

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                arr.push_back(i);

                if (i != n / i)
                    arr.push_back(n / i);
            }
        }

        int ans = 0;

        for (int x : arr) {
            bool flag = true;

            for (int i = 0; i < n; i += x) {
                int j = i + x - 1;
                int cnt = d[j] - d[i];

                if (nums[j] > nums[i])
                    cnt++;

                if (cnt > 1 || pmax[i] > smin[i]) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                ans += x;
        }

        return ans;
    }
};
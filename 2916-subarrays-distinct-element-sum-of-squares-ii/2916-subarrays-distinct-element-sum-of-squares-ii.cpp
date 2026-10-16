
class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> arr;
    int n;

    void apply(int idx, int l, int r, long long val) {
        long long len = r - l + 1;
        arr[idx].sq = (arr[idx].sq
            + 2 * val % MOD * arr[idx].sum % MOD
            + len % MOD * val % MOD * val % MOD) % MOD;

        arr[idx].sum = (arr[idx].sum + len * val) % MOD;
        arr[idx].lazy = (arr[idx].lazy + val) % MOD;
    }

    void push(int idx, int l, int r) {
        if (arr[idx].lazy == 0 || l == r) return;

        int mid = (l + r) / 2;
        apply(idx * 2, l, mid, arr[idx].lazy);
        apply(idx * 2 + 1, mid + 1, r, arr[idx].lazy);
        arr[idx].lazy = 0;
    }

    void update(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(idx, l, r, 1);
            return;
        }

        push(idx, l, r);
        int mid = (l + r) / 2;

        update(idx * 2, l, mid, ql, qr);
        update(idx * 2 + 1, mid + 1, r, ql, qr);

        arr[idx].sum =
            (arr[idx * 2].sum + arr[idx * 2 + 1].sum) % MOD;

        arr[idx].sq =
            (arr[idx * 2].sq + arr[idx * 2 + 1].sq) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        arr.resize(4 * n);

        unordered_map<int, int> mp;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = mp.count(nums[i]) ? mp[nums[i]] : -1;

            update(1, 0, n - 1, prev + 1, i);

            mp[nums[i]] = i;
            ans = (ans + arr[1].sq) % MOD;
        }

        return ans;
    }
};
class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idx;
    };
    int n;
    vector<int> NI;
    vector<vector<Node>> dp;
    Node solve(vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n) {
            if (k == 0 || i >= n) {
                Node temp;
                temp.score = 0;
                return temp;
            }
        }
        if (dp[i][k].score != -1)
            return dp[i][k];
        Node skip = solve(intervals, i + 1, k);
        int weight = intervals[i][2];
        int id = intervals[i][3];
        int j = NI[i];
        Node temp = solve(intervals, NI[i], k - 1);
        Node take;
        take.score = temp.score + weight;
        take.idx = temp.idx;
        take.idx.push_back(id);
        sort(begin(take.idx), end(take.idx));
        Node result;
        if (skip.score > take.score) {
            result = skip;
        } else if (skip.score < take.score) {
            result = take;
        } else {
            result = (skip.idx < take.idx) ? skip : take;
        }
        return dp[i][k] = result;
    }
    int findN(vector<vector<int>>& nums,
              int end) { // binary search to find nxt idx
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid][0] > end) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        dp.assign(n + 1, vector<Node>(5));
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        NI.resize(n);
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            NI[i] = findN(intervals, end); // we will apply binar search
        }
        int K = 4;
        return solve(intervals, 0, K).idx;
    }
};
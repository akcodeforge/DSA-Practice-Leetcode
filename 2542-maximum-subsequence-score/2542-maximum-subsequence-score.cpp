
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums2[i], nums1[i]});
        }
        sort(arr.rbegin(), arr.rend());
        priority_queue<int, vector<int>, greater<int>> p;
        long long s = 0;
        long long ans = 0;

        for (auto [num2, num1] : arr) {
            p.push(num1);
            s += num1;
            if (p.size() > k) {
                s -= p.top();
                p.pop();
            }
            if (p.size() == k) {
                ans = max(ans, s * num2);
            }
        }
        return ans;
    }
};

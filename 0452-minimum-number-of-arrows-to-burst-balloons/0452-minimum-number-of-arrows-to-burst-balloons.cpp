bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(), points.end(), cmp);
        int n = points.size();
        int lastIntervalTime = points[0][1];
        for (int i = 1; i < n; i++) {
            if (points[i][0] <= lastIntervalTime) {
                // ans++;
                // lastIntervalTime = points[i][1];
                continue;
            } else {
                lastIntervalTime = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};
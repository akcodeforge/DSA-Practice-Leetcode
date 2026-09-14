class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n; i++) {
            int x1 = bottomLeft[i][0];
            int y1 = bottomLeft[i][1];
            int x2 = topRight[i][0];
            int y2 = topRight[i][1];
            for (int j = i + 1; j < n; j++) {
                int a1 = bottomLeft[j][0];
                int b1 = bottomLeft[j][1];
                int a2 = topRight[j][0];
                int b2 = topRight[j][1];
                int left = max(x1, a1);
                int right = min(x2, a2);

                int bottom = max(y1, b1);
                int top = min(y2, b2);
                int width = right - left;
                int height = top - bottom;
                if (width > 0 && height > 0) {
                    int side = min(width, height);
                    long long area = 1LL * side * side;
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
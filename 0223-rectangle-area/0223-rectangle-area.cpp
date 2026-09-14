class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);

        int bottom = max(ay1, by1);
        int top = min(ay2, by2);
        long long width = 1LL * (right - left);
        long long height = 1LL * (top - bottom);
        long long commA = 0;
        if (width > 0 && height > 0) {
            commA = 1LL * width * height;
        }
        long long Aa = 1LL * (ax2 - ax1) * (ay2 - ay1);
        long long Ab = 1LL * (bx2 - bx1) * (by2 - by1);
        return Aa + Ab - commA;
    }
};
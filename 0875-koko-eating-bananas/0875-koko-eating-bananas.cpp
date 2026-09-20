class Solution {
public:
    bool check(int mid, vector<int>& piles, int h) {
        int n = piles.size();
        long long count = 0;
        for (int i = 0; i < n; i++) {
            // if(count>h) return false;
            if (piles[i] <= mid) {
                count++;
            } else if (piles[i] % mid == 0) {
                count += (long long)(piles[i] / mid);
            } else {
                count += (long long)(piles[i] / mid + 1);
            }
        }
        if (count > (long long)(h))
            return false;
        else
            return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = -1;
        for (int i = 0; i < n; i++) {
            if (piles[i] > max)
                max = piles[i];
        }
        int minK = max;
        int lo = 1;
        int hi = max;
        int mid = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, piles, h) == true) {
                minK = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return minK;
    }
};
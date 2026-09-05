class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int flip = 0, i = 0, j = 0;
        int maxLen = INT_MIN, len = INT_MIN;
        while (j < n) {
            if (nums[j] == 1)
                j++;
            else { // nums[i]==0
                if (flip < k) {
                    flip++;
                    j++;
                } else { /// flip==k , calculate len
                    len = j - i;
                    maxLen = max(maxLen, len);
                    // i ko uske just age wale zero se ek idx age le jao
                    while (nums[i] == 1)
                        i++; // after this nums[i]==0
                    i++;
                    j++;
                }
            }
        }
        len = j - i;
        maxLen = max(maxLen, len);
        return maxLen;
    }
};
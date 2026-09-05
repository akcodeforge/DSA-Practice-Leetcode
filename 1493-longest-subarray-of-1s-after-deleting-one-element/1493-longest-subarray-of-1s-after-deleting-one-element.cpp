class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int count, i = 0, j = 0;
        int maxlen = INT_MIN, leng = INT_MIN;
        while (j < n) {
            if (nums[j] == 1)
                j++;
            else {
                if (count < 1) {
                    count++;
                    j++;
                } else {
                    leng = j - i - 1;
                    maxlen = max(maxlen, leng);
                    while (nums[i] == 1)
                        i++;
                    i++;
                    j++;
                }
            }
        }
        leng = j - i - 1;
        maxlen = max(maxlen, leng);
        return maxlen;
    }
};
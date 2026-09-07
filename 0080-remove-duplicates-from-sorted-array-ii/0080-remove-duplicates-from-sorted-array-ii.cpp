class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while (j < n) {
            int count = 0;
            int x = nums[j];
            while(j < n && nums[j] == x) {
                count++;
                j++;
            }
            nums[i] = x;
            i++;
            if (count >= 2) {
                nums[i] = x;
                i++;
            }
        }
        return i;
    }
};
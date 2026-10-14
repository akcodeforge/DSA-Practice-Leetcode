class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        vector<int> ans(num, 0);
        for (int i = 0; i < num; i++) {
            ans[i] = min(9, sum);
            sum -= ans[i];
            if (sum == 0) break;
        }
        string x = "";
        for (int i = 0; i < num; i++) {
            x += char(ans[i] + '0');
        }
        return x;
    }
};
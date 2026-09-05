class Solution {
public:
    int reverse(int x) {
        long long copy = x;
        long long ans = 0;
        if (copy < 0) {
            copy = -copy;
        }
        while (copy > 0) {
            int a = copy % 10;
            ans = ans * 10 + a;
            copy /= 10;
        }
        if (ans < INT_MIN || ans > INT_MAX)
            return 0;
        if (x < 0)
            ans = -ans;
        return ans;
    }
};
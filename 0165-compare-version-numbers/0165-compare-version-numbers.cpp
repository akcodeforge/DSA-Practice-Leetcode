class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int n = version1.size();
        int m = version2.size();
        while (i < n || j < m) {
            long long ans1 = 0;
            long long ans2 = 0;
            while (i < n && version1[i] != '.') {
                ans1 = ans1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < m && version2[j] != '.') {
                ans2 = ans2 * 10 + (version2[j] - '0');
                j++;
            }
            if (ans1 < ans2)
                return -1;
            else if (ans1 > ans2)
                return 1;
            if (i < n)
                i++;
            if (j < m)
                j++;
        }
        return 0;
    }
};
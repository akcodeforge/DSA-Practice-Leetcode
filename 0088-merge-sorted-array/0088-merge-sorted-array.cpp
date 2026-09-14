class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        a.resize(m + n);
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (a[i] <= b[j]) {
                a[k] = b[j];
                j--;
            } else if (a[i] > b[j]) {
                a[k] = a[i];
                i--;
            }
            k--;
        }
        if (i < 0) {
            while (j >= 0) {
                a[k] = b[j];
                j--;
                k--;
            }
        }
        if (j < 0) {
            while (i >= 0) {
                a[k] = a[i];
                i--;
                k--;
            }
        }
    }
};
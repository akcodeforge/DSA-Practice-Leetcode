class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> ans(numRows);

        int r = 0;
        int d = 1; 
        for (char c : s) {
            ans[r] += c;

            if (r == 0)
                d = 1;
            else if (r == numRows - 1)
                d = -1;

            r += d;
        }

        string result;

        for (string &x : ans)
            result += x;

        return result;
    }
};
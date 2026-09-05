class Solution {
public:
    void Parenthesis(string s, int a, int b, int n, vector<string>& ans) {
        if (b == n) {
            ans.push_back(s);
            return;
        }
        if (a < n)
            Parenthesis(s + '(', a + 1, b, n, ans);
        if (b < a)
            Parenthesis(s + ')', a, b + 1, n, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        Parenthesis("", 0, 0, n, ans);
        return ans;
    }
};
class Solution {
public:
    unordered_set<string> st;
    void solve(string &s, int i, int lr, int rr,  int balance, string temp) {
        if (i == s.size()) {
            if (lr == 0 && rr == 0 || balance == 0) {
                st.insert(temp);
            }
            return;
        }
        char ch = s[i];
        if (ch == '(' && lr > 0) {
            solve(s, i + 1, lr - 1, rr,
                  balance, temp);
        }
        if (ch == ')' && rr > 0) {
            solve(s, i + 1, lr, rr - 1,
                  balance, temp);
        }
        if (ch != '(' && ch != ')') {
            solve(s, i + 1, lr, rr,
                  balance, temp + ch);
        }
        else if (ch == '(') {
            solve(s, i + 1, lr, rr,  balance + 1, temp + ch);
        }
        else {
            if (balance > 0) {
                solve(s, i + 1, lr, rr,  balance - 1, temp + ch);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {\
        int lr = 0;
        int rr = 0;
        for (char ch : s) {
            if (ch == '(') {
                lr++;
            }
            else if (ch == ')') {
                if (lr > 0) lr--;
                else  rr++;
            }
        }
        solve(s, 0, lr, rr, 0, "");
        return vector<string>(st.begin(), st.end());
    }
};
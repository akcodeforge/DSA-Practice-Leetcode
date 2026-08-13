class Solution {
public:

    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char leftChar;
        char rightChar;

        Node() {
            len = pref = suff = best = 0;
            leftChar = rightChar = '#';
        }
    };

    vector<Node> seg;

    Node merge(Node &a, Node &b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.pref = a.pref;

        if (a.pref == a.len &&
            a.rightChar == b.leftChar) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;

        if (b.suff == b.len &&
            a.rightChar == b.leftChar) {
            res.suff = b.len + a.suff;
        }

        // Best answer
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best,
                           a.suff + b.pref);
        }

        return res;
    }

    void build(int idx, int l, int r, string &s) {

        if (l == r) {
            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;
            seg[idx].leftChar = s[l];
            seg[idx].rightChar = s[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {

        if (l == r) {
            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;
            seg[idx].leftChar = ch;
            seg[idx].rightChar = ch;
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, ch);
        else
            update(2 * idx + 1, mid + 1, r, pos, ch);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int> queryIndices
    ) {

        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};
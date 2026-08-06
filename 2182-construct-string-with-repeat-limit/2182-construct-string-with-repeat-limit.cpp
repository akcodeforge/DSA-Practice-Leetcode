class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";
        priority_queue<pair<char, int>> pq; /// char,freq
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        for (auto& d : mp) {
            if (d.second == 0)
                continue;
            pair<char, int> p;
            p.first = d.first;
            p.second = d.second;
            d.second = 0;
            pq.push(p);
        }
        while (pq.size() > 0) {
            char a = pq.top().first;
            int z = pq.top().second;
            pq.pop();
            int k = min(z, repeatLimit);
            while (k--) {
                ans += a;
                z -= 1;
            }
            if (z > 0) {
                if (pq.empty()) {
                    break;
                }
                char st = pq.top().first;
                int stf = pq.top().second;
                ans += st;
                stf--;
                pq.pop();
                if (stf > 0) {
                    pq.push({st, stf});
                }
                pair<char, int> q;
                q.first = a;
                q.second = z;
                if (z > 0) {
                    pq.push(q);
                }
            }
        }
        return ans;
    }
};
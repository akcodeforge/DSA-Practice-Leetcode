#define ll long long
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int i = 0;
        int j = n - 1;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            p;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            q;
        while (i <= j && p.size() < candidates) {
            p.push({costs[i], i});
            i++;
        }

        while (i <= j && q.size() < candidates) {
            q.push({costs[j], j});
            j--;
        }
        long long ans = 0;
        while (k--) {
            if (q.empty()) {
                ans += p.top().first;
                p.pop();
                if (i <= j) {
                    p.push({costs[i], i});
                    i++;
                }
            } 
            else if (p.empty()) {
                ans += q.top().first;
                q.pop();
                if (i <= j) {
                    q.push({costs[j], j});
                    j--;
                }
            } 
            else {
                int a = p.top().first;
                int b = q.top().first;
                if (a == b) {
                    int x = p.top().second;
                    int y = q.top().second;
                    if (x > y) {
                        ans += q.top().first;
                        q.pop();
                        if (i <= j) {
                            q.push({costs[j], j});
                            j--;
                        }
                    } else {
                        ans += p.top().first;
                        p.pop();
                        if (i <= j) {
                            p.push({costs[i], i});
                            i++;
                        }
                    }
                } 
                else if (a < b) {
                    ans += p.top().first;
                    p.pop();
                    if (i <= j) {
                        p.push({costs[i], i});
                        i++;
                    }
                } 
                else {
                    ans += q.top().first;
                    q.pop();
                    if (i <= j) {
                        q.push({costs[j], j});
                        j--;
                    }
                }
            }
        }
        return ans;
    }
};
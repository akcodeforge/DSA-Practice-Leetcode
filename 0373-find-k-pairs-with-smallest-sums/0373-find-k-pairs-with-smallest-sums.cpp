class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, pair<int, int>>& a,
                        const pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,int k) {
        if (nums1.empty() || nums2.empty() || k == 0) return {};
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, Compare>
            pq;
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        vector<vector<int>> ans;
        while (k-- && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int x = top.second.first;
            int y = top.second.second;
            ans.push_back({nums1[x], nums2[y]});

            if (y + 1 < nums2.size()) {
                pq.push({nums1[x] + nums2[y + 1], {x, y + 1}});
            }
        }
        return ans;
    }
};
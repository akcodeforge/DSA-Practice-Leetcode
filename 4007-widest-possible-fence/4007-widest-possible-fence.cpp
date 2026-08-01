class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        unordered_map<long long, int> freq;
        for (int x : planks)
            freq[x]++;
        vector<long long> value;
        for (auto& a : freq) {
            value.push_back(a.first);
        }
        unordered_map<long long, int> tsum;
        for (int i = 0; i < value.size(); i++) {
            int x = value[i];
            tsum[2 * x] += freq[x] / 2;
            for (int j = i + 1; j < value.size(); j++) {
                int b = value[j];
                tsum[x + b] += min(freq[x], freq[b]);
            }
        }
        int maxwidth = 1;
        for (auto& t : freq) {
            maxwidth = max(maxwidth, t.second);
        }
        for (auto& t : tsum) {
            long long sum = t.first;
            int currwidth = t.second;
            if (freq.count(sum))
                currwidth += freq[sum];
            maxwidth = max(maxwidth, currwidth);
        }
        return maxwidth;
    }
};
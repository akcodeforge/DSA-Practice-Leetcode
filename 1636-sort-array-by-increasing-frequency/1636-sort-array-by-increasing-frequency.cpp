class Solution {
public:
class cm {
    public:
        bool operator()(pair<int,int> &a, pair<int,int> &b) {
            if (a.first == b.first)
                return a.second < b.second;   // larger value first
            return a.first > b.first;         // smaller frequency first
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto ele:nums){
            mp[ele]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cm>pq;
        for(auto &ele:mp){
            pq.push({ele.second, ele.first});
        }
        vector<int>ans;
        while(pq.size()>0){
            int x=pq.top().first;
            while(x--){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};
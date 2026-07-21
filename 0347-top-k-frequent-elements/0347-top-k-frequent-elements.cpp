class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto ele:nums){
            mp[ele]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto ele:mp){
            pair<int,int>q;
            q.first=ele.second;
            q.second=ele.first;
            pq.push(q);
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
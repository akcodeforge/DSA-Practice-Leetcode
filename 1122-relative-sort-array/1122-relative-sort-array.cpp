class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto ele : arr1){
            mp[ele]++;
        }
        for(auto ele : arr2){
            int freq=mp[ele];
            int x=ele;
            while(freq--){
                ans.push_back(x);
                mp[x]--;
            }
            if(mp[x]==0) mp.erase(x);
        }
        vector<int>helper;
        for(auto ele:mp){
            int x=ele.second;
            while(x--){
                helper.push_back(ele.first);
            }
        }
        sort(helper.begin(),helper.end());
        ans.insert(ans.end(),helper.begin(),helper.end());
        return ans;
    }
};
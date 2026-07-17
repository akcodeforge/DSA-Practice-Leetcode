class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto ele:strs){
            string r=ele;
            sort(r.begin(),r.end());
            if(mp.find(r)==mp.end()){
                vector<string>v;
                v.push_back(ele);
                mp[r]=v;
            }
            else{
                mp[r].push_back(ele);
            }
        }
        for(auto ele:mp){
            vector<string>vt=ele.second;
            ans.push_back(vt);
        }
        return ans;
    }
};
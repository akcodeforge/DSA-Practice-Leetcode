class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       int n=arr.size();
       unordered_map<int , int>mp;
       unordered_set<int>s;
       for(int i=0;i<n;i++){
            mp[arr[i]]++;
       } 
       for(auto ele: mp){
        if(s.find(ele.second)!=s.end()) return false;
        else{
            s.insert(ele.second);
        }
       }
       return true;
    }
};
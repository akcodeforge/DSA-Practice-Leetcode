class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        unordered_map<char,int>mp1;
        for(auto ele:word1){
            mp1[ele]++;
        }
        unordered_map<char,int>mp2;
        for(auto ele:word2){
            mp2[ele]++;
        }
        for(auto ele :mp1){
            char ch=ele.first;
            if(mp2.find(ch)==mp2.end()) return false;
        }
        unordered_map<int,int>h1;
        unordered_map<int,int>h2;
        for(auto ele:mp1){
            int freq=ele.second;
            h1[freq]++;
        }
        for(auto ele:mp2){
            int freq=ele.second;
            h2[freq]++;
        }
        for(auto ele :h1){
            if(h2.find(ele.first)==h2.end()) return false;
            if(h2[ele.first]!=h1[ele.first]) return false;
        }
        return true;
    }
};
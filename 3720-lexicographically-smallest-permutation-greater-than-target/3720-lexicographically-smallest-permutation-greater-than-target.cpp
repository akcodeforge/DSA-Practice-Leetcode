class Solution {
public:
    bool solve(string curr,vector<int>&count,string target,string &result,int i,bool greater){
        if(i==target.size()){
            if(greater){
                result=curr;
                return true;
            }
            else return false;
        }
        for(char ch='a';ch<='z';ch++){
            if(count[ch-'a']==0) continue;
            if(greater==false && ch<target[i]) continue;
            curr.push_back(ch);
            count[ch-'a']--;
            bool isgreater = greater || ch>target[i];
            if(solve(curr,count,target,result,i+1,isgreater)){
                return true;
            }
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int>count(26,0);
        for(auto ele:s){
            int x=ele-'a';
            count[x]=count[x]+1;
        }
        string curr="";
        string result="";
        bool greater=false;
        solve(curr,count,target,result,0,greater);
        return result;
    }
};
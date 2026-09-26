class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=knowledge.size();
        unordered_map<string,string>mp;
        for(auto &x:knowledge){
            mp[x[0]]=x[1];
        }
        int i=0;
        string ans="";
        while(i<s.length()){
            if(s[i]=='('){
                i++;
                string z="";
                while(s[i]!=')'){
                    z +=s[i];
                    i++;
                }
                if(mp.find(z)!=mp.end()){
                    ans +=mp[z];
                }
                else ans+='?';
                i++;
            }
            else{
                ans +=s[i];
                i++;
            }
        }
        return ans;
    }
};
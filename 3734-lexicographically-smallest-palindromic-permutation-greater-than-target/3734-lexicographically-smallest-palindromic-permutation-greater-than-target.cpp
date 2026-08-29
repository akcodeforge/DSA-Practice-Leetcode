class Solution {
public:
    char mid='$';
    int halflen=0;
    string result="";
    bool solve(string curr,vector<int>&count,string target,int i,bool greater){
        if(curr.size()==halflen){
            string candidate=curr;
            string rightHalf=curr;
            reverse(rightHalf.begin(),rightHalf.end());
            if(mid!='$'){
                candidate +=mid;
            }
            candidate +=rightHalf;  
            if(candidate > target){
                result = candidate;
                return true;
            }
            return false;
        }
        for(char ch='a';ch<='z';ch++){
            if(count[ch-'a']==0) continue;
            if(greater==false && ch<target[i]) continue;
            curr.push_back(ch);
            count[ch-'a']--;
            bool isgreater = greater || ch>target[i];
            if(solve(curr,count,target,i+1,isgreater)){
                return true;
            }
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size(); 
        vector<int>count(26,0);
        for(auto ele:s){
            int x=ele-'a';
            count[x]=count[x]+1;
        }
        int odd=0;
        for(int i=0;i<count.size();i++){
            int x=count[i];
            if(x%2!=0){
                odd++;
                mid=i+'a';  
            }
        }
        if(odd>1) return "";
        for(int i=0;i<count.size();i++){
            count[i] /=2;
        }
        halflen=n/2;
        string curr="";
        bool greater=false;
        solve(curr,count,target,0,greater);
        return result;
    }
};
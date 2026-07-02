class Solution {
public:
    bool consecutiveSetBits(int n) {
        if(n==0) return false;
        string ans=" ";
        while(n>0){
            int a=n%2;
            ans.push_back('0'+a);
            n/=2;
        }
        int count=0;
        for(int i=0;i<ans.length()-1;i++){
            if(ans[i]=='1') {
                if(ans[i]==ans[i+1]) count++;
            }
        }
        if(count==1) return true;
        else return false;
    }
};
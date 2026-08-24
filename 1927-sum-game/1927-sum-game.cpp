class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int lsum=0;
        int rsum=0;
        int leftQ=0;    
        int rightQ=0;    
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') leftQ ++;
            else lsum +=num[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?') rightQ ++;
            else rsum +=num[i]-'0';
        }
        if((leftQ+rightQ)%2!=0){
            return true;
        }
        return 2*lsum+9*leftQ!=2*rsum+9*rightQ;
    }
};
class Solution {
public:
int dp[30001][2];
    int solve(vector<int>& prices,int i,bool on){
        int n=prices.size();
        if(i==n) return 0;
        if(dp[i][on]!=-1) return dp[i][on];
        int ans=INT_MIN;
        ans=solve(prices,i+1,on);
        if(on){
            ans=max(ans,(prices[i]+solve(prices,i+1,false)));
        }
        else{
            ans=max(ans,(solve(prices,i+1,true)-prices[i]));
        }
        return dp[i][on]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,false);
    }
};
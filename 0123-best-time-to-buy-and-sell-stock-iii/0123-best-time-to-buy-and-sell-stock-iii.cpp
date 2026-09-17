class Solution {
public:
    int dp[100000][3][2];
    int solve(int k,vector<int>& prices,int i,bool on){
        int n=prices.size();
        if(i==n || k==0) return 0;
        if(dp[i][k][on]!=-1) return dp[i][k][on];
        int ans=INT_MIN;
        ans=solve(k,prices,i+1,on);
        if(on){
            ans=max(ans,(prices[i]+solve(k-1,prices,i+1,false)));
        }
        else{
            if(k>0){
            ans=max(ans,(solve(k,prices,i+1,true)-prices[i]));
            }
        }
        return dp[i][k][on]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(2,prices,0,false);
    }
};
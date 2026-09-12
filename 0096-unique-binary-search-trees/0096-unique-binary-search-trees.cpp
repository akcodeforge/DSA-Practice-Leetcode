class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0) return 1;
        if(n==1 || n==2) return n;
        if(dp[n]!=-1) return dp[n];
        int sum=0;
        for(int i=1;i<=n;i++){
            sum +=solve(i-1,dp)*solve(n-i,dp);
        }
        return dp[n]=sum;

    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
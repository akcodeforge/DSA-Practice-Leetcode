class Solution {
public:
    double dp[30][30][105] ;
    double solve(int r,int c,int n,int k){
        if(r<0 || c<0 || r>=n || c>=n) return 0;
        if(k==0) return 1;
        if(dp[r][c][k] > -0.9) return dp[r][c][k];
        double ans=0.0;
        ans +=solve(r+1,c+2,n,k-1)*(0.125);
        ans +=solve(r+2,c+1,n,k-1)*(0.125);
        ans +=solve(r+1,c-2,n,k-1)*(0.125);
        ans +=solve(r+2,c-1,n,k-1)*(0.125);
        ans +=solve(r-1,c+2,n,k-1)*(0.125);
        ans +=solve(r-2,c+1,n,k-1)*(0.125);
        ans +=solve(r-1,c-2,n,k-1)*(0.125);
        ans +=solve(r-2,c-1,n,k-1)*(0.125);
        return dp[r][c][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,-1,sizeof dp);
        return solve(row,column,n,k);
    }
};
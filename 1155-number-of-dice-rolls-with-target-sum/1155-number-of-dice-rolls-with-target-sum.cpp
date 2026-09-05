#define ll long long int
#define MOD 1000000007
class Solution {
public:
    vector<vector<ll> > dp;
    int solve(int n, int k , int target,vector<vector< ll >> &dp){
        if(n==0 && target==0) return 1;
        if(n==0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int sum=0;
        for(int v=1;v<=k;v++){
            if(target-v<0) continue;
            sum = (sum+solve(n-1,k,target-v,dp))%MOD;
        }
        return dp[n][target] = sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35,vector<ll>(1005,-1));
        return solve(n,k,target,dp);
    }
};
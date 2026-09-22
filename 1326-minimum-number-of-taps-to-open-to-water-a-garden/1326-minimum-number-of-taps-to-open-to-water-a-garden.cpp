#define ll long long int
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int INF = 1e9;
        vector<ll>dp(n+1,INF);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            for(int j=start;j<=end;j++){
                if (dp[j] == INF)
                    continue;
                dp[end]=min(dp[end],dp[j]+1);
            }
        }
        return dp[n]== INF ? -1:dp[n];
    }
};
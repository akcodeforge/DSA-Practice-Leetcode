
class Solution {
public:
    using ll = long long;
    ll n, m;
    vector<vector<int>>mt;
    ll dp[55][55][55];

    ll solve(ll i, ll j, ll x) {
        int y=i+j-x;
        if (i > n or j > m or x > n or y < 1 or y > m or mt[i][j] == -1 or
            mt[x][y] == -1) {
            return -1e9;
        }
        if (i == n && j == m) return mt[i][j];
        if (dp[i][j][x] != -1) return dp[i][j][x];

        ll result = INT_MIN;
        result = max(result, solve(i + 1, j, x + 1));
        result = max(result, solve(i + 1, j, x));
        result = max(result, solve(i, j + 1, x + 1));
        result = max(result, solve(i, j + 1, x));

        if (result < 0) return dp[i][j][x] = -1e9;

        int cherries = (i == x && j == y) ? mt[i][j] : (mt[i][j] + mt[x][y]);

        return dp[i][j][x] = result + cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof dp);
        mt.resize(55,vector<int>(55,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mt[i+1][j+1]=grid[i][j];
            }
        }
        int ans= solve(1,1,1);
        return max(0,ans);
    }
};
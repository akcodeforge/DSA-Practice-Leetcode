class Solution {
public:
    int solve(string word1, string word2,int i,int j,vector<vector<int> >&dp){
        if(i==word1.size()){
            return word2.size()-j;
        }
        if(j==word2.size()){
            return word1.size()-i;
        }
        if(word1[i]==word2[j]) {
            return dp[i][j]=solve(word1,word2,i+1,j+1,dp);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+min({solve(word1,word2,i+1,j,dp),solve(word1,word2,i,j+1,dp),solve(word1,word2,i+1,j+1,dp)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};
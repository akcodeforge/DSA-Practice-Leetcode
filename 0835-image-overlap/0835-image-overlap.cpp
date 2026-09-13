class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        for(int i=-(n-1);i<=n-1;i++){
            for(int j=-(n-1);j<=n-1;j++){
                int z=0;
                for(int a=0;a<n;a++){
                    for(int b=0;b<n;b++){
                        int x=a+i;
                        int y=b+j;
                        if(x>=0 && x<n && y>=0 && y<n && img1[a][b]==1 && img2[x][y]==1) z++;
                    }
                }
                ans=max(ans,z);
            }
        }
        return ans;
    }
};
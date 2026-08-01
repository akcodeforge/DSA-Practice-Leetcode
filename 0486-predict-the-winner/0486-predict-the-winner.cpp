class Solution {
public:
    int solve(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(i==j) return nums[i];
        int takei=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int takej=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int p1=solve(0,n-1,nums);
        int sum=0;
        for(int x:nums){
            sum +=x;
        }
        int p2=sum-p1;
        if(p1>=p2 ) return true;
        else return false;
    }
};
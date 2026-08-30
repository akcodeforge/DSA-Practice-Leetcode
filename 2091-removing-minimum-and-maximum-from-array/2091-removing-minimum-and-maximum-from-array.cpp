class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2) return n;
        int mini=INT_MAX;
        int minI=-1;
        int maxi=INT_MIN;
        int maxI=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                minI=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                maxI=i;
            }
        }
        int start=0;
        int mid=0;
        int end=0;
        if(minI<maxI){
            start=minI+1;
            end=n-maxI;
            mid=maxI-minI;
        }
        else{
            start=maxI+1;
            end=n-minI;
            mid=minI-maxI;
        }
        vector<int>ans{start,end,mid};
        sort(ans.begin(),ans.end());
        return (ans[0]+ans[1]);
    }
};
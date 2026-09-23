class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int add=0;
        for(int i=0;i<n;i++){
            add +=nums[i];
        }
        int tt=add-x;
        if(tt<0) return -1;
        add=0;
        int i=0;
        int count=-1e9;
        for(int j=0;j<n;j++){
            add +=nums[j];
            while(add>tt){
                add -=nums[i];
                i++;
            }
            if(tt==add){
                count=max(count,j-i+1);
            }
        }
        return (count==-1e9) ? -1:n-count;
    }
};
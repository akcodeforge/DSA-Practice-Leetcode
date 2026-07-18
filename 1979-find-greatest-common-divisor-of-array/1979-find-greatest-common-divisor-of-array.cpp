class Solution {
public:
int find(int min,int max){
    for(int i=min;i>=2;i--){
        if(min%i==0 && max%i==0) return i;
    }
    return 1;
}
    int findGCD(vector<int>& nums) {
        int minm=INT_MAX;
        int maxm=INT_MIN;
        for(auto ele:nums){
            maxm=max(maxm,ele);
            minm=min(minm,ele);
        }
        if(maxm%minm==0) return minm;
        else{
            return find(minm,maxm);
        }
    }
};
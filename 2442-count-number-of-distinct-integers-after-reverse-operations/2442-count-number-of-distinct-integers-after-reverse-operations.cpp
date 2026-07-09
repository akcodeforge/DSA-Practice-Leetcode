class Solution {
public:
int reverse(int n){
    int ans=0;
    while(n>0){
        ans *=10;
        ans +=(n%10);
        n =n/10;
    }
    return ans;
}
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            nums.push_back(reverse(nums[i]));
        }
         for(int i=0;i<2*n;i++){
            s.insert(nums[i]);
        }
        return s.size();
    }
};
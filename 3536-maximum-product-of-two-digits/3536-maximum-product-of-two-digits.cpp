class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n>0){
            ans.push_back(n%10);
            n /=10;
        }
        sort(ans.begin(),ans.end());
        int s=ans.size();
        return ans[s-2]*ans[s-1];
    }
};
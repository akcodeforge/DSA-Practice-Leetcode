class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int>fabo{1,1};
        while(fabo.back()<=k){
            int n=fabo.size();
            fabo.push_back(fabo[n-1]+fabo[n-2]);
        }
        int n=fabo.size();
        int ans=0;
        int rem=k;
        for(int i=n-2;i>=0;i--){
            if(fabo[i]<=rem){
                rem=rem-fabo[i];
                ans++;
            }
            if(rem==0){
                return ans;
            }
        }
        return ans;
    }
};
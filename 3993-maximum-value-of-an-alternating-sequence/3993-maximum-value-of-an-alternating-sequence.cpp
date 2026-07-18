class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        vector<long long>ans{n,s,m};
        long long x=0;
        if(n==1) return s;
        if((n-1)%2==1) x=n-1;
        else x=n-2;
        return 1LL *s+((x+1)/2)*m-(x/2);
    }
};
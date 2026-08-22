class Solution {
public:
    int sum(int n){
        int ans=0;
        while(n>0){
            int a=n%10;
            ans +=a;
            n/=10;
        }
        return ans;
    }
    int prod(int n){
        int ans=1;
        while(n>0){
            int a=n%10;
            ans *=a;
            n/=10;
        }
        return ans;
    }
    bool checkDivisibility(int n) {
        return (n%(sum(n)+prod(n))==0);
    }
};
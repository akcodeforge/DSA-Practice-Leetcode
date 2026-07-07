class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        while(n>0){
            int a=n%10;
            if(a!=0) x = (x*10)+a;
            n=n/10;
        }
        long long y=0;
        long long sum=0;
        while(x>0){
            int a=x%10;
            sum +=a;
            y = (y*10)+a;
            x=x/10;
        }
        return y*sum;
    }
};
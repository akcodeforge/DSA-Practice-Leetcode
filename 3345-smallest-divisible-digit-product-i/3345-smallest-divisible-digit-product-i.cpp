class Solution {
public:
    int prod(int x){
        int ans=1;
        while(x>0){
            int a=x%10;
            ans *=a;
            x /=10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int i=n;
        while(true){
            if(prod(i)%t==0) return i;
            i++;
        }
    }
};
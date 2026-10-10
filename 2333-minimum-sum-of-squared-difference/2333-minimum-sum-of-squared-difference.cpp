
class Solution {
public:
    #define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        ll z= k1 + k2;
        vector<int> f(100001,0);
        for(int i=0;i<n;i++){
            int x=abs(nums1[i]-nums2[i]);
            f[x]++;
        }
        ll sum=0;
        for(int i=f.size()-1;i>0;i--){
            if(z==0) break;
            if(f[i]>0){
                if(z>=f[i]){
                    z-=f[i];
                    f[i-1]+=f[i];
                    f[i]=0;
                }
                else{
                    f[i]-=z;
                    f[i-1]+=z;
                    z=0;
                }
            }
        }
        for(int i=0;i<f.size();i++){
            sum += (1LL * i * i * f[i]);
        }
        return sum;
    }
};
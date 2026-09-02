class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int minodd=INT_MAX;
        for(auto x:nums1){
            if(x%2!=0){
                minodd=min(minodd,x);
            }
        }
        /// try to make all odd;
        bool odd=true;
        for(int i=0;i<n;i++){
            if(nums1[i] % 2 == 0){
                if(minodd>nums1[i]){
                    odd=false;
                    break;
                }
            }
        }
        if(odd) return true;
        
        // for every even check if any odd present not possible to make even;
        for(int x:nums1){
            if(x%2!=0) return false;
        }
        return true;
    }
};
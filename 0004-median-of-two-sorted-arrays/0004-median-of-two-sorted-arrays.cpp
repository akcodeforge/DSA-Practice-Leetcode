class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m=nums1.size();
       int n=nums2.size();
       for(int i=0;i<n;i++){
        nums1.push_back(nums2[i]);
       }
       sort(nums1.begin(),nums1.end());
        int t=m+n;
       if(t%2==0){
        int mean=t/2;
        return (nums1[mean - 1] + nums1[mean]) / 2.0;
       }
       else{
        int mean=t/2;
        return nums1[mean];
       }
    }
};
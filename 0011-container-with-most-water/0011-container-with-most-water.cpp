class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=INT_MIN;
        int n=height.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int x=min(height[i],height[j]);
            int len=j-i;
            int area=(x*len);
            maxArea=max(maxArea,area);
            if(height[i]<=height[j]){
                i++;
            }
            else j--;
        }
        return maxArea;
    }
};
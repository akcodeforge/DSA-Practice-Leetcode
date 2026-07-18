class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int s=flowerbed.size();
        int count=0;
        if(s==1) return flowerbed[0]==0;
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            count++;
        }
        for(int i=1;i<s-1;i++){
            if(flowerbed[i]==1) continue;
            else{
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    count++;
                    flowerbed[i]=1;
                }
            }
        }
        if(flowerbed[s-1]==0 && flowerbed[s-2]==0){
            flowerbed[s-1]=1;
            count++;
        }
        return count>=n;
    }
};
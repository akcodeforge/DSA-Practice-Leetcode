class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int x=0;
        int ans=0;
        for(int i=0;i<gas.size();i++){
            int a=gas[i]-cost[i];
            total +=a;
            x +=a;
            if(x<0){
                ans=i+1;
                x=0;
            }
        }
        if(total<0) return -1;
        return ans;
    }
};
class Solution {
public:
    typedef pair<int,int>pip;  // tottal profit,number of box,number of box;
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pip>pq;
        int n=boxTypes.size();
        for(int i=0;i<n;i++){
            // int profit=boxTypes[i][0]*boxTypes[i][1];
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }
        int ans=0;
        while(pq.size()>0){
            int top=pq.top().second;
            if(top==truckSize){
                ans +=(pq.top().first *pq.top().second);
                return ans;
            }
            else if(top>truckSize){
                ans +=(truckSize*(pq.top().first));
                return ans;
            }
            else{
                ans +=(pq.top().first *pq.top().second);
                truckSize -=top;
                pq.pop();
            }
        }
        return ans;
    }
};
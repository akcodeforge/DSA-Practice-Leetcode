class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int x :stones){
            pq.push(x);
        }
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            if(a==pq.top()) pq.pop();
            else{
                int b=pq.top();
                pq.pop();
                pq.push(a-b);
            }
        }
        if(pq.size()!=0) {
            return pq.top();
        }
        else return 0;
    }
};
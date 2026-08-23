class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        priority_queue<int>pq;
        while(numOnes>0){
            pq.push(1);
            numOnes--;
        }
        while(numZeros>0){
            pq.push(0);
            numZeros--;
        }
        while(numNegOnes>0){
            pq.push(-1);
            numNegOnes--;
        }
        int ans=0;
        while(k>0){
            ans +=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>p;
        for(int x:nums){
            p.push(x);
        }
        int a=p.top();
        p.pop();
        int b=p.top();
        return (a-1)*(b-1);
    }
};
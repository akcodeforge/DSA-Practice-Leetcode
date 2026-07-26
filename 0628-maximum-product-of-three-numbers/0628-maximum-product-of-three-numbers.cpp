class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int>p;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int x:nums){
            p.push(x);
            q.push(x);
        }
        int d=p.top();
        p.pop();
        int a =p.top()*d;
        p.pop();
        a *=p.top();
        int b=d;
        b*=q.top();
        q.pop();
        b*=q.top();
        return max(a,b);
    }
};
class Solution {
public:
    typedef pair<int,pair<int,int>>pip;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<pip,vector<pip>,greater<pip>>q;
        int mx=INT_MIN;
        for(int i=0;i<k;i++){
            mx=max(mx,nums[i][0]);
            q.push({nums[i][0],{i,0}});
        }
        int min=q.top().first;
        int start=min , end=mx;
        while(true){
            int val=q.top().first;
            int a=q.top().second.first;
            int b=q.top().second.second;
            q.pop();
            b++;
            // update the ans;
            if(mx-val<end-start){
                start=val;
                end=mx;
            }
            if(b>=nums[a].size()) break;
            q.push({nums[a][b],{a,b}});
            mx=max(mx,nums[a][b]);
        }
        return {start,end};
    }
};
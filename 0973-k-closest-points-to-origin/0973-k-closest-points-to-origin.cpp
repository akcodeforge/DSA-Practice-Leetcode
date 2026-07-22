class Solution {
public:
    int distance(int x,int y){
        return (x*x+y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<points.size();i++){
            int x=distance(points[i][0],points[i][1]);
            pair<int,int>p;
            p.first=points[i][0];
            p.second=points[i][1];
            pq.push({x,p});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()>0){
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            ans.push_back({a,b});
            pq.pop();
        }
        return ans;
    }
};
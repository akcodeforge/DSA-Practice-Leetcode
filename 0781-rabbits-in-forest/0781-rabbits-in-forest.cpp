class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[answers[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto ele:mp){
            pq.push({ele.first,ele.second});
        }
        int ans=0;
        while(pq.size()>0){
            int a=pq.top().first;
            int b=pq.top().second;
            if(a==0){
                ans+=b;
                pq.pop();
            }
            else if(a+1>=b){
                ans+=(a+1);
                pq.pop();
            }
            else{
                pq.pop();
                ans+=(a+1);
                int x=a+1;
                int y=b;
                pq.push({a,y-x});
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[answers[i]]++;
        }
        int ans=0;
        for(auto ele:mp){
            int a=ele.first;
            int b=ele.second;
            if(a==0){
                ans+=b;
            }
            // else if(a+1>=b){
            //     ans+=(a+1);
            // }
            else{
                int rem=b/(a+1);
                int per=b%(a+1);
                if(per==0){
                    ans+=(rem*(a+1));
                }
                else{
                    ans+=((rem*(a+1))+a+1);
                }
            }
        }
        return ans;
    }
};
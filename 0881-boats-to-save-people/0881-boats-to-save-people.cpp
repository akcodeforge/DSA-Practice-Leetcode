class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        int boat=0;
        while(i<=j){
            int high=people[j];
            int low=people[i];
            if(low+high <= limit){
                i++;
            }
            j--;
            boat++;
        }
        return boat;
    }
};
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>ans;
        for(int i=0;i<students.size();i++){
            ans.push(students[i]);
        }
        int i=0;
        int count=0;
        while(ans.size()>0 && count!=ans.size()){
            if(sandwiches[i]==ans.front()){
                count=0;
                i++;
                ans.pop();
            }
            else {
                int a=ans.front();
                ans.pop();
                ans.push(a);
                count++;
            }
        }
        return ans.size();
    }
};
class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<string>ans;
        int num=0;
        string curr="";
        for(auto x:s){
            if(x>='0' && x<='9'){
                num =num*10 +(x-'0');
            }
            else if(x=='['){
                nums.push(num);
                ans.push(curr);
                num=0;
                curr="";
            }
            else if(x==']'){
                int r=nums.top();
                nums.pop();
                string prev=ans.top();
                ans.pop();
                string temp=curr;
                curr=prev;
                while(r--){
                    curr+=temp;
                }
            }
            else {
                curr +=x;
            }
        }
        return curr;
    }
};
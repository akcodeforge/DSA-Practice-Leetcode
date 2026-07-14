class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector <int>ans;
        string s="123456789";
        int n=s.length();
        for(int i=2;i<10;i++){
            for(int j=0;j<=n-i;j++){
                int digit=stoi(s.substr(j,i));
                if(digit>=low && digit<=high) ans.push_back(digit);
            }
        }
        return ans;
    }
};
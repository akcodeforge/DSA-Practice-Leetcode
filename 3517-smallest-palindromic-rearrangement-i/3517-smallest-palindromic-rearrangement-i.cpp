class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(char x:s){
            freq[x-'a']++;
        }
        string left="";
        string middle="";
        for(int i = 0; i < 26; i++) {
            char ch = char(i+'a');
            int f = freq[i];
            if(f%2==1) middle +=ch;
            for(int j=0;j<f/2;j++){
                left +=ch;
            }
        }
        string right=left;
        reverse(right.begin(),right.end());
        string ans="";
        ans +=left+middle+right;
        return ans;
    }
};
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        string ans="";
        int i=0;
        while(n>0 && m>0){
            ans +=word1[i];
            ans +=word2[i];
            i++;
            n--;
            m--;
        }
        if(n>0){
            while(n>0 ){
            ans +=word1[i];
            i++;
            n--;
        }
        }
        if(m>0){
            while( m>0){
            ans +=word2[i];
            i++;
            m--;
        }
        }
        return ans;
    }
};
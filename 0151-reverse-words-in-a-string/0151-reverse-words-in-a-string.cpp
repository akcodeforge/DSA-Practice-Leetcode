class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string d="";
        while(!s.empty() && s.back()==' '){
            s.pop_back();
        }
        int t=0;
        n=s.length();
        while(t<n){
            if(d.size()==0 && s[t]==' ') {
                t++;
            }
            else if(s[t]!=' '){
                d +=s[t];
                t++;
            }
            else if(d.size()!=0 && s[t]==' '){
                d +=' ';
                while(t < n && s[t]==' ') t++;
            }
        }

        string ans="";
        int r=d.size();
        int i=r-1;
        int j=r-1;
        while(j>=0){
            if(d[j]==' '){
                for(int z=j+1;z<=i;z++){
                    ans +=d[z];
                }
                ans +=' ';
                i=j-1;
            }
            else if(j==0){
                for(int z=j;z<=i;z++){
                    ans +=d[z];
                }
                i=j;
            }
            j--;
        }
        return ans;
    }
};
class Solution {
public:
long long nCr(int n,int r,int k){
    /// ncr==nc(n-r);
    /// 5c3==5c2;
    /// not 5c2==5c3
    r=min(r,(n-r));
    long long result=1;
    for(int i=1;i<=r;i++){
        result = (result * (n-r+i)) / i;
        if(result>=k) return k;
    }
    return result;
}
    string smallestPalindrome(string s, int k) {
        int n=s.length();
        vector<int>freq(26,0);
        for(int i=0;i<n/2;i++){
            // if(n%2==1 && i==n/2) continue;
            freq[s[i]-'a']++;
        }
        string left="";
        string mid="";
        if(n%2!=0){
            mid +=s[n/2];
        }
        for(int i=0;i<n/2;i++){
            bool notfound=false;
            for(int j=0;j<26;j++){   /// which charecter will be push
                if(freq[j]>0){
                    freq[j] -=1;  //// fixing thw position
                    //// count the number of ways 
                    long long way=1;
                    int letters=0;
                    for(int c=0;c<26;c++){
                        letters +=freq[c];
                    }
                    for(int c=0;c<26;c++){
                        if(freq[c]>0){
                            way *=nCr(letters,freq[c],k);
                            letters -=freq[c];
                        }
                        if(way>=k) break;
                    }
                    if(way >=k){   /// this block contain my kth one
                         left.push_back(j+'a');   /// fixed this caharcter at i th position
                         notfound=true;
                         break;
                    }
                    k -=way;   ///when k>=way;  
                    freq[j] +=1;
                }
            }
            if(notfound==false) return "";
        }
        string right=left;
        reverse(right.begin(),right.end());
        return left+mid+right;
    }
};
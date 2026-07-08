class Solution {
public:
    bool validDigit(int n, int x) {
       string a = to_string(n);
        char c = x + '0';
        if(a[0] == c) return false;
           for(int i=1;i<a.length();i++){
            if(a[i] == c) return true; 
        } 
          return false;  
    }
};
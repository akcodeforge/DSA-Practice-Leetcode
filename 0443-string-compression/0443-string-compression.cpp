class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int j=0;
        while(i<n){
            int count=0;
            char ch=chars[i];
            while(i<n && chars[i]==ch){
                i++;
                count++;
            }
            chars[j++]=ch;
            if(count>1){
                string s=to_string(count);
                for(auto z:s){
                    chars[j++]=z;
                }
            }

        }
        return j;
    }
};
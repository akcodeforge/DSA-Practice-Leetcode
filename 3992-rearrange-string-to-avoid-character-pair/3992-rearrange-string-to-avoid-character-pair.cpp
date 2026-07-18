class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string yt="";
        string xt="";
        string d="";
        for(auto ele :s){
            if(ele==y) yt +=ele;
            else if(ele==x) xt +=ele;
            else d +=ele;
        }
        return yt+d+xt;
    }
};
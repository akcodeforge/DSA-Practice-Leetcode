class Solution {
public:
    bool checkValidString(string s) {
        int i = 0;   
        int j = 0; 

        for (char ch : s) {
            if (ch == '(') {
                i++;
                j++;
            }
            else if (ch == ')') {
                i--;
                j--;
            }
            else { 
                i--;   
                j++; 
            }
            if (j < 0) return false;
            i = max(0, i);
        }
        return (i == 0);
    }
};
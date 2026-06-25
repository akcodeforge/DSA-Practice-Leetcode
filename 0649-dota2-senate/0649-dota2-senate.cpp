class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> r;
        queue<int> d;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }
        while(r.size()>0 && d.size()>0){
            int ri=r.front();
            int di=d.front();
            r.pop();
            d.pop();
            if(ri<di){
                r.push(ri+n);
            }
            else d.push(di+n);
        }
        return (r.size()>0)? "Radiant":"Dire";
    }
};
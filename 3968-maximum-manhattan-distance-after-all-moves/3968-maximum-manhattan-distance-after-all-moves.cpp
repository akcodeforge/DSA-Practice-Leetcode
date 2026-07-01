class Solution {
public:
    int maxDistance(string moves) {
        if(moves.size()==0) return 0;
          int x=0;  
          int y=0;
        int k=0;
        for(int i=0;i<moves.length();i++){
           if(moves[i]=='U') {
            y +=1;
        }
        else if(moves[i]=='D') {
            y -=1;
        }
        else if(moves[i]=='L') {
            x -=1;
        }
        else if(moves[i]=='R') {
            x +=1;
        }
            else if(moves[i]=='_'){
                k+=1;
            }
           
        }
        return abs(-x)+abs(0-y)+k;
    }
};
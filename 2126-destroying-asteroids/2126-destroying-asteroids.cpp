class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int count = 0;
        long long Mass = mass;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] <= Mass) {
                Mass += asteroids[i];
                asteroids[i]=0;
            } 
            else
                count++;
        }
        while (count > 0) {
            int temp = 0;
            for (int i = 0; i < asteroids.size(); i++) {
                if (asteroids[i] <= Mass) {
                    Mass += asteroids[i];
                    asteroids[i]=0;
                } 
                else
                    temp++;
            }
        if(temp==count) return false;
        count=temp;
        }
        return true;
    }
};
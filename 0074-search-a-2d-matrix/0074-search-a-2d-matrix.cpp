class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool flag = false;
        int x=0;
        for (int i=0;i<n;i++){
            if (target>=matrix[i][0] && target<=matrix[i][m-1]){
                flag =true;
                x=i;
            }
        }
        if(flag==false)  return false;
        else {
            for(int i=0;i<m;i++){
                if(target==matrix[x][i]) return true;
            }
        }
        return false;
    }
};
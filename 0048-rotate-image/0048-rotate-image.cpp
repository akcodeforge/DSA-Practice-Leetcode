class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // transpose
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // inverse;
        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
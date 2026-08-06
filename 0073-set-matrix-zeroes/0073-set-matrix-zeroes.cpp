class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        for (int col = 0; col < n; ++col) {
            if (matrix[0][col] == 0) {
                firstRowZero = true;
                break;
            }
        }

        for (int row = 0; row < m; ++row) {
            if (matrix[row][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }

        if (firstRowZero) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }

        if (firstColZero) {
            for (int row = 0; row < m; ++row) {
                matrix[row][0] = 0;
            }
        }
    }
};
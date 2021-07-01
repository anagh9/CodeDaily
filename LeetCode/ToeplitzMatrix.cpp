// https://leetcode.com/problems/toeplitz-matrix/submissions/

class Solution {
public:
    bool isToeplitzMatrix1(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() - 1; i++) {
            for (int j = 0;  j < matrix[0].size() - 1; j++) {
                if (matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
            }
        }
        return true;
    }

    bool isToeplitzMatrix2(vector<vector<int>>& m) {
        for (int i{1}; i < size(m); ++i)
            if (!equal(next(begin(m[i])), end(m[i]), begin(m[i - 1]))) return false;
        return true;
    }

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i = matrix.size() - 1, j = 0;
        int x, y;

        for (; i != 0 || j != matrix[0].size(); i != 0 ? --i : ++j) {
            int p = matrix[i][j];

            for (x = i + 1, y = j + 1; x < matrix.size() && y < matrix[0].size(); ++y, ++x) {
                if (matrix[x][y] != p)
                    return false;
            }
        }
        return true;
    }
};


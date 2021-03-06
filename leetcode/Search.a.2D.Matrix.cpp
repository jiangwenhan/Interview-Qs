// treat the Matrix is a N * M increasing array
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = matrix.size();
        if (N == 0) return false;
        int M = matrix[0].size();
        
        int l = 0, r = N * M - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int x = mid / M, y = mid % M;
            if (matrix[x][y] < target) l = mid + 1;
            else r = mid;
        }
        int x = l / M, y = l % M;
        return matrix[x][y] == target;
    }
};

// Solve it as a normal Row Column Increasing Matirx
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = matrix.size();
        if (N == 0) return false;
        int M = matrix[0].size();
        if (M == 0) return false;
        int x = N - 1, y = 0;
        while (x >= 0 && y < M)
        {
            if (matrix[x][y] == target) return true;
            if (target > matrix[x][y]) y++;
            else x--;
        }
        return false;
    }
};

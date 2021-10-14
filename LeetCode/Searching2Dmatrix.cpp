class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        while (i<m && j>=0)
        {
        if (matrix[i][j] == x)
        {
            return true;
        }
        else if(matrix[i][j] < x)
        {
            i++;
        }
        else{
            j--;
        }
        }
        return false;
    }
};
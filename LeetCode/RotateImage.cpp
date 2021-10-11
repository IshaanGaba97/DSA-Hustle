class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int r = arr.size();
        // first transpose 
        for(int i = 0; i < r; i++)
        {
        for (int j = i; j < r; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
        }
        // reverse columns
        for(int i = 0; i < r; i++)
        {
        int li = 0;
        int ri = r-1;
        while (li < ri)
        {
            int temp = arr[i][li];
            arr[i][li] = arr[i][ri];
            arr[i][ri] = temp;
            li++;
            ri--;
        } 
    }
    }
};
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int minCost(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
{

    for (int i = dp.size() - 1; i >= 0; i--)
    {
        for (int j = dp[0].size() - 1; j >= 0; j--)
        {
            // 4 options - last position, last row, last column, other maze
            if (i == dp.size() - 1 && j == dp[0].size() - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == dp.size() - 1)
            {
                dp[i][j] = dp[i][j + 1] + arr[i][j];
            }
            else if (j == dp[0].size() - 1)
            {
                dp[i][j] = dp[i + 1][j] + arr[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + arr[i][j];
            }
        }
    }
    return dp[0][0];
}

int main()
{

    int n;
    int m;

    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // for storing the min cost of traversal from that position
    vector<vector<int>> dp(n, vector<int>(m));

    cout << minCost(n, m, arr, dp);
}
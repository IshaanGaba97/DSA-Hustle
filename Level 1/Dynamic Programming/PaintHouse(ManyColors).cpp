#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int c;
    int n;
    cin >> n;
    cin >> c;
    vector<vector<int>> arr(n, vector<int>(c));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(c));

    for (int j = 0; j < c; j++)
    {
        dp[0][j] = arr[0][j];
    }

    for (int j = 0; j < c; j++)
    {
        dp[0][j] = arr[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int min = INT_MAX;

            for (int k = 0; k < c; k++)
            {
                if (k != j)
                {
                    if (dp[i - 1][k] < min)
                    {
                        min = dp[i - 1][k];
                    }
                }
            }
            dp[i][j] = arr[i][j] + min;
        }
    }
    int min = INT_MAX;
    for (int k = 0; k < c; k++)
    {
        if (dp[n - 1][k] < min)
        {
            min = dp[n - 1][k];
        }
    }
    cout << min;
}
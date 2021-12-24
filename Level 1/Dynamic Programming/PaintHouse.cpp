#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<long>> dp(n, vector<long>(3));
    dp[0][0] = arr[0][0];                       //red
    dp[0][1] = arr[0][1];                       //blue 
    dp[0][2] = arr[0][2];                       //green
    for(int i = 1; i < n; i++){
        dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);   //red
        dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);   //blue
        dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);   //green
    }
    long ans = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    cout << ans << endl;
}  
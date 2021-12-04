#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int jumpT(int n, vector<int>& jumps, vector<int>& dp)
{
  // write your code here
  
  dp[n] = 0;
  for(int i = n-1; i >= 0; i--)
  {
      int minvalue = 30;
      for(int j = 1; j <= jumps[i] && i + j <= n; j++)
      {
          int val = dp[i+j] + 1;
          minvalue = min(minvalue, val);
      }
      dp[i] = minvalue;
  }
  return dp[0];
}

int main() {

  int n;
  cin >> n;

  vector<int> jumps(n);

  for (int i = 0; i < n; i++)
  {
    cin >> jumps[i];
  }

  vector<int> dp(n + 1, 0);

  int ans = jumpT(n, jumps, dp);

  if (ans < 30)
    cout << ans;
  else
    cout << "null";
}
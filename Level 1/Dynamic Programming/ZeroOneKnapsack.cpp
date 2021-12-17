#include <iostream>
#include <vector>

using namespace std;

void zeroOneKnapsack(int n, vector<int> val, vector<int> wts, int cap) {

vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));               // 2d matrix for dp storing val and weight 
for(int i = 1; i < dp.size(); i++){
    for(int j = 1; j < dp[0].size(); j++){
        if(j >= wts[i - 1]){                       //when j can play 
            int rcap = j - wts[i-1];
            if(dp[i-1][rcap] + val[i - 1] > dp[i-1][j]){       //when sum of val and i-1 is greater
                dp[i][j] = dp[i-1][rcap] + val[i - 1];
            }
            else{
                dp[i][j] = dp[i-1][j];       //when i doesnot bat
            }
        }
        else{
            dp[i][j] = dp[i-1][j];           //when i doesnot bat
        }
    }
}
cout << dp[n][cap];     
}

int main() {

  int n;
  cin >> n;

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int cap;        // capacity
  cin >> cap;

  zeroOneKnapsack(n, val, weight, cap);
}
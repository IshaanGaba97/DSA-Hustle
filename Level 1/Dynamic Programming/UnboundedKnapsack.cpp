#include <iostream>
#include <vector>

using namespace std;

void unboundedKnapsack(int n, vector<int> val, vector<int> weight, int cap) {

// write your code here
vector<int> dp(cap+1);
dp[0] = 0;

for(int bagc = 1; bagc <= cap; bagc++){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(weight[i] <= bagc){
            int rbagc = bagc - weight[i];
            int rbagv = dp[rbagc];
            int tbagv = rbagv + val[i];
            if(tbagv > max){
                max = tbagv;
            }
        }
    }
    dp[bagc] = max; 
}
cout << dp[cap];
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
  int cap;
  cin >> cap;

  unboundedKnapsack(n, val, weight, cap);
}
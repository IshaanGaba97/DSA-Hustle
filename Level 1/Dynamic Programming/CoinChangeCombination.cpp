#include <iostream>
#include <vector>
using namespace std;

void coinchangecombination(vector<int> coins, int amt){
    vector<int> dp(amt+1);
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++){
        for(int j = coins[i]; j < dp.size(); j++){
        dp[j] += dp[j - coins[i]];
        }
        }
    }   
    cout << dp[amt];
}

int main(){
    int n;
    cin >> n;
    vector<int> coins(n,0);
    for(int i = 0; i < coins.size(); i++){
        cin >> coins[i];
    }
    int amt;
    cin >> amt;
    coinchangecombination(coins, amt);
}
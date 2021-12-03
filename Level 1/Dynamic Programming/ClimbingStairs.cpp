#include <iostream>
using namespace std;

// memoization approach
int cs(int n, int qb[]){
    if(n==0)
    {
        return 1;
    }else if(n < 0){
        return 0;
    }
    
    if(qb[n] != 0){
        return qb[n];
    }
    int nm1 = cs(n-1, qb);
    int nm2 = cs(n-2, qb);
    int nm3 = cs(n-3, qb);
    int cp = nm1 + nm2 + nm3;
    qb[n] = cp;
    return cp;
}

// tablular approach
int cstab(int n){
    int* dp = new int[n + 1];
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++){
        if(i == 1){
            dp[i] = dp[i-1];
        }else if(i == 2){
            dp[i] = dp[i-1] + dp[i-2];
        }else{
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n+1];
    cout<<cs(n, arr)<<endl;
    cout<<cstab(n)<<endl;
}
#include <iostream>
using namespace std;

int cs(int arr[], int n){
    // write your code here
    int* dp = new int[n+1];
    dp[n] = 1;               //base case
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= arr[i] && i + j < n+1; j++){
            dp[i] += dp[i+j];
        }
    }
    return dp[0];
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}
#include<iostream>
using namespace std;

int factorial(int n){
    // write your code here
    if(n == 1)
    {
        return 1;
    }
    int fnm = factorial(n-1); 
    int fn = n * fnm;
    return fn;
}


int main(){
    int n; cin>>n;
    cout << factorial(n);
}

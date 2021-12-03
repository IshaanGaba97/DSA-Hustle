// fibonacci memoized
#include <iostream>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1)
    {
        return n;
    }
    
    int fibnm1 = fib(n-1);
    int fibnm2 = fib(n-2);
    int fibn = fibnm1 + fibnm2;
    
    return fibn;
}

int fibmem(int n, int qb[]){
    if(n == 0 || n == 1)
    {
        return n;
    }
    
    if(qb[n] != 0){
        return qb[n];
    }
    
    int fibnm1 = fib(n-1);
    int fibnm2 = fib(n-2);
    int fibn = fibnm1 + fibnm2;
    
    qb[n] = fibn;
    return fibn;
}

int main() {
    int n;
    int* arr = new int[n+1];
    cin >> n;
    cout << fibmem(n, arr);
    return 0;
}
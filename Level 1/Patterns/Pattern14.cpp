#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= 10; i++)
    {
        int v = n * i;
        cout << n << " * " << i << " = " << v << endl;
    }
    return 0;
}
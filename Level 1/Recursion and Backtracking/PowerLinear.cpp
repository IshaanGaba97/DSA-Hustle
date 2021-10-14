#include <iostream>
using namespace std;

int power(int x, int n)
{
    // write your code here
    if (n == 0)
    {
        return 1;
    }
    int pnm1 = power(x, n - 1);
    int pn = pnm1 * x;
    return pn;
}

int main()
{
    int n, x;
    cin >> x >> n;
    cout <<power(x, n);
}

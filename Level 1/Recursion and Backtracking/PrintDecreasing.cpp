#include <iostream>

using namespace std;

void printDec(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    printDec(n - 1);
}

int main()
{
    int n;
    cin >> n;
    printDec(n);
    return 0;
}
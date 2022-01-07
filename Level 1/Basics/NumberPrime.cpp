#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int count = 0;
        int n;
        cin >> n;
        for (int j = 2; j * j <= n; j++)
        {
            if (n % j == 0)
            {
                count++;
                break;
            }
        }
        if (count == 0)
        {
            cout << "prime" << endl;
        }
        else
        {
            cout << "not prime" << endl;
        }
    }
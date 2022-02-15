#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    
    int first = 0;
    int second = 1;
    for(int i = 1 ; i <= n; i++)
    {
        cout << first << endl;
        int sum = first + second;
        first = second;
        second = sum;
    }
    return 0;
}
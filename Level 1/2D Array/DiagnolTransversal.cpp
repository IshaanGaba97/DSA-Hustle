#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int** arr1 = new int*[n];
    for(int i = 0; i < n; i++)
    arr1[i] = new int[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr1[i][j];
        }
    }
    
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            cout << arr1[i][j] << endl;
        }
    }
}
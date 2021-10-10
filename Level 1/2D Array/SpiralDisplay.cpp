#include<iostream>

using namespace std;

int main()
{
    int r, c;
    cin >> r;
    cin >> c;

    int** arr = new int*[r];
    for(int i = 0; i < r; i++)
    arr[i] = new int[c];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int j = 0; j < c; j++)
    {
        for(int i = 0; i < r; i++)
        {
            cout << arr[i][j];
        }
    }

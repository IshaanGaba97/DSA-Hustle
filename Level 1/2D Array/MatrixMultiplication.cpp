#include<iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    int** arr1 = new int*[n];
    for(int i = 0; i < n; i++)
    arr1[i] = new int[m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr1[i][j];
        }
    }

    int x , y;
    cin >> x;
    cin >> y;
    int** arr2 = new int*[x];
    for(int i = 0; i < x; i++)
    arr2[i] = new int[y];


    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cin >> arr2[i][j];
        }
    }

    if(m != x)
    {
        cout << "Invalid input" << endl;
    }

    int** arr3 = new int*[n];
    for(int i = 0; i < n; i++)
    arr3[i] = new int[y];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < y; j++)
        {
            for(int k = 0; k < m; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cout << arr3[i][j] <<" ";
        }
        cout << endl;
    }
}
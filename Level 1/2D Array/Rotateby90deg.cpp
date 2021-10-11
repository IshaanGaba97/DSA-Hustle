// transpose + reverse columns
#include<iostream>
using namespace std;
int main()
{
    int r;
    cin >> r;

    int** arr = new int*[r];
    for(int i = 0; i < r; i++)
    arr[i] = new int[r];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < r; i++)
    {
        for (int j = i; j < r; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for(int i = 0; i < r; i++)
    {
        int li = 0;
        int ri = r-1;
        while (li < ri)
        {
            int temp = arr[i][li];
            arr[i][li] = arr[i][ri];
            arr[i][ri] = temp;
            li++;
            ri--;
        }
        
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cout << arr[i][j] <<" ";
        }
    }
}

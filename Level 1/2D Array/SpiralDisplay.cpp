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

    int minr = 0;
    int minc = 0;
    int maxr = r-1;
    int maxc = c-1;
    int tne = r * c;
    int cnt = 0;
    while (cnt < tne)
    {
        // left wall 
        for (int i = minr,  j = minc; i <= maxr && cnt < tne; i++)
        {
            cout << arr[i][j]<<endl;
            cnt++;
        }
        minc++;

        // bottom wall 
        for (int i = maxr,  j = minc; j <= maxc && cnt < tne; j++)
        {
            cout << arr[i][j]<<endl;
            cnt++;
        }
        maxr--;

        // right wall 
        for (int i = maxr,  j = maxc; i >= minr && cnt < tne; i--)
        {
            cout << arr[i][j]<<endl;
            cnt++;
        }
        maxc--;

        // top wall 
        for (int i = minr,  j = maxc; j >= minc && cnt < tne; j--)
        {
            cout << arr[i][j]<<endl;
            cnt++;
        }
        minr++;
    }
    
}   

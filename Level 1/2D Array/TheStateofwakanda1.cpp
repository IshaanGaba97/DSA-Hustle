// wave transversal question 

#include<iostream>

using namespace std;

int main()
{
    int r, c;
    cin >> r;
    cin >> c;

    int** arr1 = new int*[r];
    for(int i = 0; i < r; i++)
    arr1[i] = new int[c];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for(int j = 0; j < c; j++)
    {
        if(j%2 == 0){
        for(int i = 0; i < r; i++)
        {
            cout << arr1[i][j] << endl;
        }
        }

        else{
        for(int i = r; i >= 0; i--)
        {
            cout << arr1[i][j] << endl;
        }
        }
    }

    return 0;
}
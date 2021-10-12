#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int** arr = new int*[n];
    for(int i = 0; i < n; i++)
    arr[i] = new int[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int svj = 0;
        for (int j = 1; j < n; j++)
        {
            if(arr[i][svj] > arr[i][j])
            {
                svj = j;
            }
        }
        
        bool flag = true;
        for (int k = 0; k < n; k++)
        {
            if(arr[k][svj] > arr[i][svj])
            {
                flag = false;
                break;
            }
        }
        
        if(flag == true)
        {
            cout << arr[i][svj];
            return 0;
        }
        cout << "Invalid input" << endl;
    }
    
}
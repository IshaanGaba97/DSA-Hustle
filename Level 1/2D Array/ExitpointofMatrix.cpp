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
    
    int dir = 0;                  // direction is 0 - e,  1 - s, 2 - w,  3 - n
    int i = 0;
    int j = 0;

    while(true)
    {
        dir = (dir + arr[i][j]) % 4;
        if(dir == 0){//east
            j++;
        }
        else if(dir == 1){//south
            i++;
        }
        else if(dir == 2){//west
            j--;
        }
        else if(dir == 3){//north
            i--;
        }

        if(i<0){ // exit condition
            i++;
            break;
        }
        else if(j < 0){
            j++;
            break;
        }
        else if(i == r){
            i--;
            break;
        }
        else if(j == c){
            j--;
            break;
        }
    }

    cout << i << endl;
    cout << j << endl;
}
    

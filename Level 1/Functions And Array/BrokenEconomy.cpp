#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data;
    cin >> data;

    int lo = 0;
    int hi = n-1;
    int floor = 0;
    int ceil = 0;
    while(lo <= hi)
    {
        int mid = (lo + hi)/2;
        if (data < arr[mid])
        {
            hi = mid - 1;
            ceil = arr[mid];
        }
        else if(data > arr[mid])
        {
            floor = arr[mid];
            lo = mid + 1;
        }
        else{
            floor = arr[mid];
            ceil = arr[mid];
            break;
        }
    }
    cout << ceil << endl;
    cout << floor << endl;
    }
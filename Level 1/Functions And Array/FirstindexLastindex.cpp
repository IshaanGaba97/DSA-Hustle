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
    
    int fi = -1;
    
    while(lo <= hi)
    {
        int mid = (lo + hi)/2;
        if (data < arr[mid])
        {
            hi = mid - 1;
        }
        else if(data > arr[mid])
        {
            lo = mid + 1;
        }
        else
        {
            fi = mid;
            hi = mid - 1;
        }
    }
    cout << fi << endl;
    
    int li = -1;
    lo = 0;
    hi = n-1;
    
    while(lo <= hi)
    {
        int mid = (lo + hi)/2;
        if (data < arr[mid])
        {
            hi = mid - 1;
        }
        else if(data > arr[mid])
        {
            lo = mid + 1;
        }
        else
        {
            li = mid;
            lo = mid + 1;
        }
    }
    
    cout << li << endl;
    return 0;
}
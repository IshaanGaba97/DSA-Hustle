#include<iostream>
#include<math.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    
    int limit = pow(2, n);

    for (int i = 0; i < limit; i++)
    {
        for (int j = n-1; j >= 0; j--)
        {
            int rem = i % 2;
            i = i / 2;

            if (rem == 0)
            {
                
            }
            else
            {

            }
            
        }
        
    }
    
    return 0;
}
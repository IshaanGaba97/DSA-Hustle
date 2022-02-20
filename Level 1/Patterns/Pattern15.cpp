#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int star  = 1;
    int space = n/2;
    int val = 1;
    
    for(int i = 1; i <= n; i++)
    {
        //cout << space << star;
        for(int j = 1; j <= space; j++)
        {
            cout << "	";
        }
        
        int cval = val;
        for(int j = 1; j <= star; j++)
        {
            cout << cval << "	";
            if(j <= star/2)
            {
                cval++;
            }
            else
            {
                cval--;
            }
        }
        
        if(i <= n/2)
        {
            space--;
            star = star + 2;
            val++;
        }
        
        else
        {
            space++;
            star = star - 2;
            val--;
        }
        cout << endl;
    }
    
    return 0;
}
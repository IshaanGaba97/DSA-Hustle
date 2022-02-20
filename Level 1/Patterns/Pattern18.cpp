#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int space = 0;
    int star = n;
    for(int i = 1; i <= n; i++)
    {
        // cout << space << star;
        
        for (int j = 1; j <= space; j++)
        {
            cout << "	";
        }
        
        for (int j = 1; j <= star; j++)
        {
            if( i > 1 && i <= n/2 && j > 1 && j < star)
            {
                cout << "	";
            }
            else
            {
            cout << "*	";
            }
        }
        
        if( i <= n/2 )
        {
        space++;
        star = star - 2;
        }
        
        else
        {
            space--;
            star = star + 2;
        }
        cout << endl;
    }
}
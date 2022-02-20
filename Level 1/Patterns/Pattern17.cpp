#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int space = n/2;
    int star = 1;
    
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            if (i == n/2 + 1)
            {
                cout << "*	";
            }
            else
            {
            cout <<"	";
            }
        }
        
        for (int j = 1; j <= star; j++)
        {
            cout << "*	";
        }
        
        if (i <= n/2)
        {
            star++;
        }
        else 
        {
            star--;
        }
        cout << endl;
    }
    return 0;
}  
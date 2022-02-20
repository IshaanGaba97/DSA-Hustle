#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int star = 1;
    int space = 2*n-3;
    int val = 1;
    
    for (int i = 1; i <= n; i++)
    {
        int val = 1;
        for(int j = 1; j <= star; j++)
        {
            cout << val << "	";
            val++;
        }
        
         for(int j = 1; j <= space; j++)
        {
            cout << "	";
        }
        
        if(i == n)
        {
            star--;
            val--;
        }
         for(int j = 1; j <= star; j++)
        {
            val--;
            cout << val << "	";
        }
        
        
        space = space - 2;
        star = star + 1;
        
        cout << endl;
    }
    return 0;
}

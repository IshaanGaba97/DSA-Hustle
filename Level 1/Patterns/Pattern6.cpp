#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int st = (n/2) + 1;
    int sp = 1;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= st; j++)
        {
            cout <<"*	";
        }
        
        for(int j = 1; j <= sp; j++)
        {
            cout <<"	";
        }
        
        for(int j = 1; j <= st; j++)
        {
            cout << "*	";
        }
        
        if(i <= n/2)
        {
            st = st - 1;
            sp = sp + 2;
        }
        else
        {
            st = st + 1;
            sp = sp - 2;
        }
        cout << endl;
    }
	return 0;
}

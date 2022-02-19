#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int st = 1;
    int sp = n-1;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sp; j++)
        {
            cout <<"	";
        }
        
        for(int j = 1; j <= st; j++)
        {
            cout <<"*	";
        }
        
        sp--;
        cout << endl;
    }
	return 0;
}

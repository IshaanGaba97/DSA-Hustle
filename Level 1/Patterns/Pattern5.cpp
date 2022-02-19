#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    int st = 1;
    int sp = n/2;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sp; j++)
        {
            cout << "	";
        }
        
        for(int j = 1; j <= st; j++)
        {
            cout << "*	";
        }
        
        if(i <= n/2)
        {
            sp--;
            st = st + 2;
        }
        
        else
        {
            st = st - 2;
            sp++;
            
        }
        cout << endl;
    }
    return 0;
}
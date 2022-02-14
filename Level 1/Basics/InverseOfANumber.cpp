#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv){
int n;
    cin >> n;
    int inverse = 0;
    int op = 1;
    while(n != 0)
    {
        int od = n%10;
        int id = op;
        int ip = od;
        
        inverse = inverse + (id * ((int)pow(10,ip-1)));
        
        n = n/10;
        op++;
    }
    cout << inverse << endl;
    return 0;
}
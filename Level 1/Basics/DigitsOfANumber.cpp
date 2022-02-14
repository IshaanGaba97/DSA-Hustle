#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int nod = 0;
    int temp = n;
    while(temp!=0)
    {
        temp = temp / 10;
        nod++;
    }
    
    int div = (int)pow(10,nod-1);
    while(div!=0)
    {
        int rem = n / div;
        n = n % div;
        div = div/10;
        cout << rem << endl;
    }
    return 0;
}

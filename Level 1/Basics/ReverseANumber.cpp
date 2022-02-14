#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    while(n>0)
    {
        int rem = n % 10;
        cout << rem << endl;
        n = n / 10;
    }
    return 0;
}
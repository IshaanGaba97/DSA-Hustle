#include<iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin>>n;
    
    for(int div = 1; div*div <= n; div++)
    {
        cout << div*div << endl;
    }
    
}
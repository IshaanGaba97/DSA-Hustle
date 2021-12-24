#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    int k;
    cin >> n;
    cin >> k;
    
    long same = k * 1;
    long diff = k * (k - 1);
    long total = same + diff;
    
    for(int i = 3; i <= n; i++){
        same = diff * 1;
        diff = total * (k - 1);
        total = same + diff;
    }
    cout << total;
    return 0;
}
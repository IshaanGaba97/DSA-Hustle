#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < v.size(); i++){
        cin >> v[i];
    }
    int inc = v[0];
    int exc = 0;
    for(int i = 1; i < v.size(); i++){
        int ninc = exc + v[i];
        int nexc = max(inc, exc);

        inc = ninc;
        exc = nexc;
    }
    int ans = max(inc, exc);
    cout << ans;
}
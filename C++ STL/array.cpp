#include <iostream>
#include <array>

using namespace std;

// stl array is based on simple array only
int main() {
    int basic[] = {1, 2, 3};
    array<int,4> a = {1, 2, 3, 4};
    
    int size = a.size();
    
    for(int i = 0; i < size; i++){
        cout << a[i] << endl;
    }
    
    cout << "element at index 2 is " << a.at(2) << endl;
    cout << "Empty or not ->" << a.empty() << endl;
    
    cout << "front element -> " << a.front() << endl;
    cout << "back element -> " << a.back() << endl;
}
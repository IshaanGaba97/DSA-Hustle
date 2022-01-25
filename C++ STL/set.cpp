#include <iostream>
#include<set>

using namespace std;

int main() {
    set<int> s;
    
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(0);
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    
    for(int i : s){
        cout << i << endl;
    }
    cout << endl;
    s.erase(s.begin());
    
    for(int i : s){
        cout << i << endl;
    }
    
    cout << "wether -5 the element is present or not -> "<< s.count(-5) << endl;
    
    set<int>::iterator itr = s.find(3);
    cout << "value present at itr ->" << *itr << endl; 
    
}
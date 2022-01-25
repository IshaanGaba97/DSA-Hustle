#include <iostream>
#include<queue>

using namespace std;

int main() {
    //maxheap
    priority_queue<int> maxi;
    
    //minheap
    priority_queue<int, vector<int>, greater<int>> mini;
    
    //max heap priority queue
    maxi.push(1);
    maxi.push(4);
    maxi.push(3);
    maxi.push(2);
    
    int n = maxi.size();
    for(int i = 0; i < n; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;
    
    //min heap priority queue
    mini.push(1);
    mini.push(4);
    mini.push(3);
    mini.push(2);
    
    for(int i = 0; i < n; i++){
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;
    
    cout << "empty or not ->" << mini.empty() << endl;
}
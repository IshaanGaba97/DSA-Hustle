#include <iostream>
#include <string>
#include<queue>

using namespace std;

int main() {
    queue<string> q;
    
    q.push("tokyo");
    q.push("denver");
    q.push("nairobi");

    cout << "first element of the queue -> " << q.front() << endl;
    q.pop();
    cout << "first element of the queue -> " << q.front() << endl;
    
    cout << "size of the queue -> " << q.size() << endl;
}
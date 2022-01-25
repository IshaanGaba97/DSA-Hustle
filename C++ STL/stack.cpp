#include <iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
    stack<string> s;
    
    s.push("tokyo");
    s.push("denver");
    s.push("nairobi");

    cout << "top element -> " << s.top() << endl;
    s.pop();
    cout << "top element -> " << s.top() << endl;
    
    cout << "size of stack -> " << s.size() << endl;
    
    cout << "empty or not ->" << s.empty() << endl;
}
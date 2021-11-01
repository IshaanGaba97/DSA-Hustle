#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> st;
    string s;
    cin >> s;
    
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == ')')
        {
            if(st.top() == '('){
                cout << "true" << endl;
                return 0;
            }
            else{
                while(st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
        }
        else
        {
            st.push(ch);
        }
    }
    cout << "false" << endl;
}
#include <iostream>
#include <ctype.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void celebPrblm(vector<string> &v, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (v[a][b] == '1')
        {
            st.push(b); // a knows b -> b can be celebrity
        }
        else
        {
            st.push(a); // a doesnt know b -> a can be celebrity
        }
    }

    int pc = st.top();
    st.pop();
    for (int i = 0; i < n; i++)
    {
        if (i != pc)
        {
            if (v[i][pc] == '0' || v[pc][i] == '1')
            {
                cout << "none" << endl;
                return;
            }
        }
    }

    cout << pc << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.push_back(str);
    }
    celebPrblm(s, n);
}

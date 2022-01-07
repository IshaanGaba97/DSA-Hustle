#include <iostream>
#include <vector>
#include <stack>
#include <ctype.h>
#include <string>

using namespace std;

int pre(char optor)
{
    if (optor == '+')
    {
        return 1;
    }
    else if (optor == '-')
    {
        return 1;
    }
    else if (optor == '*')
    {
        return 2;
    }
    else
    {
        return 2;
    }
}

int operation(int v1, int v2, char optor)
{
    if (optor == '+')
    {
        return v1 + v2;
    }
    else if (optor == '-')
    {
        return v1 - v2;
    }
    else if (optor == '*')
    {
        return v1 * v2;
    }
    else
    {
        return v1 / v2;
    }
}

int main()
{
    string str;
    getline(cin, str);

    stack<int> opnds;
    stack<char> optors;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (isdigit(ch))
        {
            opnds.push(ch - '0');
        }

        else if (ch == '(')
        {
            optors.push(ch);
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (optors.size() > 0 && optors.top() != '(' && pre(ch) <= pre(optors.top()))
            {
                char optor = optors.top();
                optors.pop();
                int v2 = opnds.top();
                opnds.pop();
                int v1 = opnds.top();
                opnds.pop();
                int opv = operation(v1, v2, optor);
                opnds.push(opv);
            }
            optors.push(ch);
        }

        else if (ch == ')')
        {
            while (optors.top() != '(')
            {
                char optor = optors.top();
                optors.pop();
                int v2 = opnds.top();
                opnds.pop();
                int v1 = opnds.top();
                opnds.pop();
                int opv = operation(v1, v2, optor);
                opnds.push(opv);
            }
            optors.pop();
        }
    }

    while (optors.size() > 0)
    {
        char optor = optors.top();
        optors.pop();
        int v2 = opnds.top();
        opnds.pop();
        int v1 = opnds.top();
        opnds.pop();
        int opv = operation(v1, v2, optor);
        opnds.push(opv);
    }

    int ans = opnds.top();
    cout << ans;

    return 0;
}
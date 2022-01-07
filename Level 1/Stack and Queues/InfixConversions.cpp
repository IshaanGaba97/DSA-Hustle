#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <ctype.h>
using namespace std;

int pre(char ch)
{
    if (ch == '+')
    {
        return 1;
    }
    else if (ch == '-')
    {
        return 1;
    }
    else if (ch == '*')
    {
        return 2;
    }
    else
    {
        return 2;
    }
}

int main()
{
    string str;
    getline(cin, str);

    stack<string> postSt;
    stack<string> preSt;
    stack<char> opSt;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(')
        {
            opSt.push(ch);
        }

        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            string s = string(1, ch);
            postSt.push(s);
            preSt.push(s);
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (opSt.size() > 0 && opSt.top() != '(' && pre(ch) <= pre(opSt.top()))
            {
                char op = opSt.top();
                opSt.pop();
                string s = string(1, op);

                string postVal2 = postSt.top();
                postSt.pop();
                string postVal1 = postSt.top();
                postSt.pop();

                string postVal = (postVal1 + postVal2 + s);
                postSt.push(postVal);

                string preVal2 = preSt.top();
                preSt.pop();
                string preVal1 = preSt.top();
                preSt.pop();
                string preVal = (s + preVal1 + preVal2);
                preSt.push(preVal);
            }
            opSt.push(ch);
        }

        else if (ch == ')')
        {
            while (opSt.size() > 0 && opSt.top() != '(')
            {
                char op = opSt.top();
                opSt.pop();
                string s = string(1, op);

                string postVal2 = postSt.top();
                postSt.pop();
                string postVal1 = postSt.top();
                postSt.pop();

                string postVal = (postVal1 + postVal2 + s);
                postSt.push(postVal);

                string preVal2 = preSt.top();
                preSt.pop();
                string preVal1 = preSt.top();
                preSt.pop();

                string preVal = (s + preVal1 + preVal2);
                preSt.push(preVal);
            }
            opSt.pop();
        }
    }

    while (opSt.size() > 0)
    {
        char op = opSt.top();
        opSt.pop();
        string s = string(1, op);

        string postVal2 = postSt.top();
        postSt.pop();
        string postVal1 = postSt.top();
        postSt.pop();

        string postVal = (postVal1 + postVal2 + s);
        postSt.push(postVal);

        string preVal2 = preSt.top();
        preSt.pop();
        string preVal1 = preSt.top();
        preSt.pop();

        string preVal = (s + preVal1 + preVal2);
        preSt.push(preVal);
    }

    string postAns = postSt.top();
    string preAns = preSt.top();
    cout << postAns << endl;
    cout << preAns << endl;
}
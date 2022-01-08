#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <ctype.h>
using namespace std;

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


int main() {
  string exp;
  getline(cin, exp);

  stack<int> vs;
  stack<string> is;
  stack<string> ps;
  
  for(int i = exp.length() - 1; i >= 0; i--){
      char ch = exp[i];
      
      if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
          
          int v1 = vs.top();
          vs.pop();
          int v2 = vs.top();
          vs.pop();
          int v = operation(v1, v2, ch);
          vs.push(v);
          
          string iv1 = is.top();
          is.pop();
          string iv2 = is.top();
          is.pop();
          
          string iv = "(" + iv1 + ch + iv2 + ")";
          is.push(iv);
          
          string pv1 = ps.top();
          ps.pop();
          string pv2 = ps.top();
          ps.pop();
          
          string pv = pv1 + pv2 + ch;
          ps.push(pv);
          
      } else {
          string s = string(1, ch);
          vs.push(ch - '0');
          is.push(s);
          ps.push(s);
      }
  }
  int value = vs.top();
  vs.pop();
  string iexp = is.top();
  is.pop();
  string pexp = ps.top();
  ps.pop();
  cout << value << endl;
  cout << iexp << endl;
  cout << pexp << endl;
  return 0;
}
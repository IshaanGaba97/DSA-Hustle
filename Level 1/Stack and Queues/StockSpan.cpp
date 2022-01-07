#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void display(vector<int> a)
{
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}
vector<int> solve(vector<int> arr)
{
  int n = arr.size();
  vector<int> span(n);
  stack<int> st;
  st.push(0);
  span[0] = 1;
  for (int i = 1; i < n; i++)
  {
    while (st.size() && arr[i] > arr[st.top()])
    {
      st.pop();
    }
    if (st.size() == 0)
    {
      span[i] = i + 1;
    }
    else
    {
      span[i] = i - st.top();
    }
    st.push(i);
  }
  return span;
}
int main(int argc, char **argv)
{
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int> span(n, 0);
  span = solve(arr);
  display(span);
  return 0;
}
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}

vector<int> solve(vector<int>arr)
{
  //alternate -> -a then +   
  int n = arr.size();
  vector<int> nge(n);
  stack<int> st;
  st.push(0);
  for(int i = 1; i < n; i++){
      while(st.size() > 0 && arr[i] > arr[st.top()]){
          int pos = st.top();
          nge[pos] = arr[i];
          st.pop();
      }
      st.push(i);
  }
  while(st.size() > 0){
      int pos = st.top();
      nge[pos] = -1;
      st.pop();
  }
  return nge;
}

int main(int argc, char** argv)
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int>nge(n, 0);
  nge = solve(arr);
  display(nge);
  return 0;
}
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
  //write your code here
  int n = arr.size();
  vector<int>nge(n, 0);
  stack<int> st;
  st.push(arr[n-1]);
  nge[n-1] = -1;
  for(int i = n-2; i >= 0; i--){
      //-a+
      while(st.size() > 0 && arr[i] >= st.top()){
          st.pop();
      }
      if(st.size() == 0){
          nge[i] = -1;
      }
      else{
          nge[i] = st.top();
      }
      st.push(arr[i]);
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